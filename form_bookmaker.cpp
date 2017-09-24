//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_bookmaker.h"
#include "form_prihlaseni.h"
#include "ZakladniTridy.h"
#include "Bookmakeri.h"
#include "Hraci.h"
#include "Zapasy.h"
#include "Tipy.h"
#include "Tikety.h"
#include "form_registrace.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformBookmaker *formBookmaker;
//---------------------------------------------------------------------------
__fastcall TformBookmaker::TformBookmaker(TComponent* Owner)
	: TForm(Owner)
{
  IdTiketu=-1;
	UkazSeznamUzivatelu();
	UkazSeznamBmakeru();
	UkazSeznamZapasu();
  UkazSeznamTiketu();
	eSkoreD->Enabled=false;
	eSkoreH->Enabled=false;
	dtpCas->Time=Time();
	dtpDatum->Date=Date();
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::FormShow(TObject *Sender)
{
	formPrihlaseni->Hide();  //Zakryjeme hlavni okno
	pcBookmaker->TabIndex=0; //Prepneme na prvni panel
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::FormClose(TObject *Sender, TCloseAction &Action)
{
	VymazNevyuziteZapasy(); //Vymazu nevyuzite zapasy
	VyhodnotZapasy();       //Zbytek zapasu vyhodnotim
	ZjistiUspesnostTiketu();//a vyhodnotim tikty
	formPrihlaseni->Close();//pak zavru app
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazSeznamBmakeru()
{
	libBmakeri->Clear();
	for (int i = 0; i < SeznamBmakeru->GetSeznam()->Count; i++) {
		TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
		libBmakeri->Items->Add(IntToStr(bmk->Id)+"	"+bmk->Email);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazSeznamUzivatelu()
{
	libUzivatele->Clear();
	for (int i = 0; i < SeznamUzivatelu->GetSeznam()->Count; i++) {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
		libUzivatele->Items->Add(IntToStr(uziv->Id)+"	"+uziv->Email);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazSeznamZapasu()
{
	libZapasy->Clear();
	for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
		libZapasy->Items->Add(IntToStr(zap->IdZap)+"	"+zap->JmenoD+"	"+zap->JmenoH+"	"+zap->DatZap);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazSeznamTiketu()
{
	libTikety->Clear();
	for (int i = 0; i < SeznamTiketu->GetSeznam()->Count; i++) {
		TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
		libTikety->Items->Add("ID Tiketu:	"+IntToStr(tik->IdTik)+"	ID Uzivatele:	"+IntToStr(tik->IdUziv)+"	"+DateToStr(tik->DatTik));
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazSeznamZapasuTiketu()
{
	libZapasyTiketu->Clear();
	for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
		TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (pom->IdTik==IdTiketu) {
			for (unsigned j = 0; j < (unsigned)SeznamZapasu->GetSeznam()->Count; j++) {
				TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[j]);
				if (pom->IdZap==zap->IdZap) {
					libZapasyTiketu->Items->Add("ID Tipu:	"+IntToStr(pom->IdTipu)+"Domaci:	"+zap->JmenoD+"	Hoste:	"+zap->JmenoH+"  Tip:	"+IntToStr(pom->Tip));
					break;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::UkazStatistiky(unsigned Id)
{
	int pocTiketu=0,pocTipu=0;  //pocty spravnych tipu a tiketu
	unsigned cPocTik=0,cPocTip=0;   //pocty vsech tipu a tiketu
	for (unsigned i = 0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
		TTiket *tiket=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
		if (tiket->IdUziv==Id) {
			cPocTik++;
			for (unsigned j = 0; j < (unsigned)SeznamTipu->GetSeznam()->Count; j++) {
				TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[j]);
				if (tip->IdTik==tiket->IdTik) {
					cPocTip++;
					TZapas *pom=(TZapas *)(SeznamZapasu->Najdi(tip->IdZap));
					if ((tip->Vyhra)&&(pom!=NULL)) {
						if (pom->Dohrano)
							pocTipu++; //jestli je zapas dohrany a tip byl spravny tak prictu 1 k poctu spravnych tipu
					}
				}
			}
			if (tiket->Vyplaceno) {  //jestli je tiket vplaceny a vyhra je vetsi jak 0 tak prictu 1 k poctu spravnych tiketu
				if (tiket->VyhraTik>0) {
					pocTiketu++;
				}
			}
		}
	}
	lblePocSpravnychTipu->Text=IntToStr(pocTipu)+" z "+IntToStr(cPocTip);
	lblePocVyhranychTiketu->Text=IntToStr(pocTiketu)+" z "+IntToStr(cPocTik);
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::VyhodnotZapasy()
{
	for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
		for (int j = 0; j < SeznamTipu->GetSeznam()->Count; j++) {
			TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[j]);
			if (zap->IdZap==tip->IdZap) {
				if ((zap->SkoreD-zap->SkoreH>0)&&(tip->Tip==1)) {
					tip->Vyhra=true;
					break;
				}
				else if ((zap->SkoreD-zap->SkoreH<0)&&(tip->Tip==2)) {
					tip->Vyhra=true;
					break;
				}
				else if ((zap->SkoreD-zap->SkoreH==0)&&(tip->Tip==0)) {
					tip->Vyhra=true;
					break;
				}
				else {
					tip->Vyhra=false;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::ZjistiUspesnostTiketu()
{
	int pocetZapasuTiketu;
	for (unsigned i=0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
		TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
		if (tik->Vyplaceno)
			continue;  //Kdyz je vyplaceno preskocim, kdyby byla chyba, tak ji muzu opravit tlacitkem btnVyhodnotZnovu
		pocetZapasuTiketu=ZjistiPocetZapasuTiketu(tik->IdTik);
		for (int j = 0; j < SeznamTipu->GetSeznam()->Count; j++) {
			TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[j]);
			if (tik->IdTik==tip->IdTik) {
				if (pocetZapasuTiketu>0) {
					TZapas *zap=(TZapas *)(SeznamZapasu->Najdi(tip->IdZap));
					if (zap->Dohrano) {
						if (!tip->Vyhra) {
							tik->VyhraTik=0;
							tik->Vyplaceno=true;
							break;   //jestli nejaky tip nevysel ukoncim cyklus a dam tiket jako vyhodnoceny a prohrany
						}
						pocetZapasuTiketu--;
					}
				}
				if (pocetZapasuTiketu==0) {
					TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(tik->IdUziv));
					uziv->Konto+=tik->VyhraTik;
					tik->Vyplaceno=true; //kdyz dojdu nakonec poctu zapasu v tiketu vyhodnotim tiket jako spravny a vyplatim
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
__fastcall TformBookmaker::ZjistiPocetZapasuTiketu(unsigned IdT)
{
	int vysledek=0;
	TTiket *tik=(TTiket *)(SeznamTiketu->Najdi(IdT));
	for (int i=0; i < SeznamTipu->GetSeznam()->Count; i++) {
		TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (tik->IdTik==tip->IdTik) {
    	vysledek++;  
		} 
	}   //prohledam tiket s IdT a urcim poctet zapasu
  return vysledek;
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::VymazNevyuziteZapasy()
{  //prochazim od zadu seznamem a mazu kazdy stary zapas, na ktery nebylo nikdy vsazeno, tim usetrim misto
	for (long int i = SeznamZapasu->GetSeznam()->Count-1; i >=0; i--) {
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
		if ((zap->DatZap<Date())||(zap->Dohrano)) {
			bool zaznam = false;
			for (unsigned j = 0; j < (unsigned)SeznamTipu->GetSeznam()->Count; j++) {
				TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[j]);
				if (tip->IdZap==zap->IdZap) {
					zaznam = true;
					break; //zastavim cyklus a jdu na dalsi zapas, protoze jsem nasel tip na tento zapas
				}
			}
			if (!zaznam) {
				SeznamZapasu->Zruseni(zap->IdZap);//jestli jsem nenasel tip smazu zapas
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnPridatBmkClick(TObject *Sender)
{
	libBmakeri->ItemIndex=-1;
    formRegistrace->btnRegistrovat->Tag=3;
	if(formRegistrace->ShowModal()==mrOk)
		UkazSeznamBmakeru();      // vyvolam prekresleni v listu
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnUpravBmkClick(TObject *Sender)
{
	if (libBmakeri->ItemIndex!=-1) {
		formRegistrace->btnRegistrovat->Tag=2;
		formRegistrace->ShowModal();
		UkazSeznamBmakeru();
		libBmakeri->ItemIndex=-1;
	}
	else {
		MessageDlg("Není vybrána žádná položka ze seznamu bookmakerù",mtInformation,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnNajdiBmkClick(TObject *Sender)
{
	if (lbleIdBmk->Text!="") {
		TBmaker *bmk=(TBmaker *)(SeznamBmakeru->Najdi(StrToInt(lbleIdBmk->Text)));
		if (bmk!=NULL) {
			for (unsigned i = 0; i < (unsigned)SeznamBmakeru->GetSeznam()->Count; i++) {
				TBmaker *pom=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
				if (pom->Id==bmk->Id) {
					libBmakeri->ItemIndex=StrToInt(i);
					libBmakeriClick(Sender);
					break;
				}
			}
		}
		else {
			MessageDlg("Bookmaker s ID: "+lbleIdBmk->Text+" nebyl nalezen!",mtInformation,TMsgDlgButtons() << mbOK,0);
		}
	}
	else
  	MessageDlg("Musíte zadat nìjaké ID bookmakera!!",mtInformation,TMsgDlgButtons() << mbOK,0);

}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnOdebratBmkClick(TObject *Sender)
{
	try {
		if (libBmakeri->ItemIndex==-1)
			throw "Nebyl vybrán žádný zápas!!";
		TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[libBmakeri->ItemIndex]);
		SeznamBmakeru->Zruseni(bmk->Id);
		eVybranyBmk->Text="";
		libBmakeri->ItemIndex=-1;
		UkazSeznamBmakeru();
	}	catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	} catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::libBmakeriClick(TObject *Sender)
{
	TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[libBmakeri->ItemIndex]);
	eVybranyBmk->Text=IntToStr(bmk->Id)+"	"+bmk->Email;
	lbleIdBmk->Text=IntToStr(bmk->Id);
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnPridatUzivClick(TObject *Sender)
{
	libUzivatele->ItemIndex=-1;
	formRegistrace->btnRegistrovat->Tag=0;
	if(formRegistrace->ShowModal()==mrOk)
		UkazSeznamUzivatelu();      // vyvolam prekresleni v memo
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnUpravUzivClick(TObject *Sender)
{
	if (libUzivatele->ItemIndex!=-1) {
    formRegistrace->btnRegistrovat->Tag=1;
		formRegistrace->ShowModal();
		UkazSeznamUzivatelu();
		libUzivatele->ItemIndex=-1;
	}
	else {
		MessageDlg("Není vybrána žádná položka ze seznamu uživatelù",mtInformation,TMsgDlgButtons() << mbOK,0);
	}	
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnNajdiUzivClick(TObject *Sender)
{
	if (lbleIdUziv->Text!="") {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(StrToInt(lbleIdUziv->Text)));
		if (uziv!=NULL) {
			for (unsigned i = 0; i < (unsigned)SeznamUzivatelu->GetSeznam()->Count; i++) {
				TUzivatel *pom=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
				if (pom->Id==uziv->Id) {
					libUzivatele->ItemIndex=StrToInt(i);
					libUzivateleClick(Sender);
					break;
				}
			}
		}
		else {
			MessageDlg("Uživatel s ID: "+lbleIdUziv->Text+" nebyl nalezen!",mtInformation,TMsgDlgButtons() << mbOK,0);
		}
	}
	else
		MessageDlg("Musíte zadat nìjaké ID uživatele!!",mtInformation,TMsgDlgButtons() << mbOK,0);

}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnOdebratUzivClick(TObject *Sender)
{
	try {
		if (libUzivatele->ItemIndex==-1)
			throw "Nebyl vybrán žádný uživatel!!";
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[libUzivatele->ItemIndex]);
		SeznamUzivatelu->Zruseni(uziv->Id);
		libUzivatele->ItemIndex=-1;
		UkazSeznamUzivatelu();
	}	catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	} catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::libUzivateleClick(TObject *Sender)
{
	TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[libUzivatele->ItemIndex]);
	eVybranyUziv->Text=IntToStr(uziv->Id)+"	"+uziv->Email;
	lbleStavKonta->Text=FloatToStrF(uziv->Konto,ffFixed,15,2)+" ,-KÈ";
	UkazStatistiky(uziv->Id);
  lbleIdUziv->Text=IntToStr(uziv->Id);
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnPridatZClick(TObject *Sender)
{
	try {
	if (dtpDatum->Date<Date()) {throw "Zastaraly datum";}
		if ((lbleJmenoD->Text=="")||(lbleJmenoH->Text==""))throw "Špatnì zadané jméno týmu!!";
		if ((StrToInt(eSkoreD->Text)<0)||(StrToInt(eSkoreH->Text)<0))throw "Špatnì zadaný výsledek!!";
		if ((StrToFloat(lbleKurzD->Text)<1)||(StrToFloat(lbleKurzRem->Text)<1)||(StrToFloat(lbleKurzH->Text)<1))throw "Špatnì zadaný kurz!!";
		if (dtpDatum->Date==Date()){
         dtpCas->Date=Date();        // metody Date i Time od dtpCas davaji vzdy datum i cas a datum je nastaveno podle properties Date
                                     // pak by to porovnani nefungovalo dobre, proto musime datum nastavit na aktualni hodnotu
         if (dtpCas->Time<Time())
             throw "Špatnì zadaný èas!!";
		}
		TZapas zap( SeznamZapasu->DejPosledniKlic(),lbleJmenoD->Text.Trim(),lbleJmenoH->Text.Trim(),StrToInt(eSkoreD->Text),
								StrToInt(eSkoreH->Text),StrToFloat(lbleKurzD->Text),StrToFloat(lbleKurzRem->Text),
								StrToFloat(lbleKurzH->Text),dtpDatum->Date,dtpCas->DateTime.TimeString(),false);

		SeznamZapasu->Pridani(zap);  //pridani zapasu do seznamu zapasu
		UkazSeznamZapasu();  //zobrazeni seznamu zapasu
	}
	catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	}
	catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}	
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnOdebratZClick(TObject *Sender)
{
	try {
		if (libZapasy->ItemIndex==-1)
			throw "Nebyl vybrán žádný zápas!!";
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[libZapasy->ItemIndex]);
		SeznamZapasu->Zruseni(zap->IdZap);
		UkazSeznamZapasu();
	}	catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	} catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnZmenZClick(TObject *Sender)
{
	try {
		if (libZapasy->ItemIndex==-1)throw "Vyberte nìjaký zápas!!";
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[libZapasy->ItemIndex]);
		if (dtpDatum->Date<Date()) {throw "Zastaraly datum";}
		if ((lbleJmenoD->Text=="")||(lbleJmenoH->Text==""))throw "Špatnì zadané jméno týmu!!";
		if ((StrToInt(eSkoreD->Text)<0)||(StrToInt(eSkoreH->Text)<0))throw "Špatnì zadaný výsledek!!";
		if ((StrToFloat(lbleKurzD->Text)<1)||(StrToFloat(lbleKurzRem->Text)<1)||(StrToFloat(lbleKurzH->Text)<1))throw "Špatnì zadaný kurz!!";
		if (dtpDatum->Date==Date()){
			dtpCas->Date=Date();        // metody Date i Time od dtpCas davaji vzdy datum i cas a datum je nastaveno podle properties Date
			if (dtpCas->Time<Time())    // pak by to porovnani nefungovalo dobre, proto musime datum nastavit na aktualni hodnotu
				throw "Špatnì zadaný èas!!";
		}
		zap->UpravZapas(lbleJmenoD->Text.Trim(),lbleJmenoH->Text.Trim(),StrToInt(eSkoreD->Text),StrToInt(eSkoreH->Text),
						StrToFloat(lbleKurzD->Text),StrToFloat(lbleKurzRem->Text),StrToFloat(lbleKurzH->Text),
						dtpDatum->Date,dtpCas->DateTime.TimeString(),cboDohrano->Checked);
		UkazSeznamZapasu();
		VyhodnotZapasy();
		ZjistiUspesnostTiketu();

    libZapasy->ItemIndex=0;
		libZapasyClick(Sender);
	}
	catch (char *chyba){
		MessageDlg(chyba,mtWarning,TMsgDlgButtons() << mbOK,0);
	}
	catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}	
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::cboDohranoClick(TObject *Sender)
{
	if (cboDohrano->Checked) {
		eSkoreD->Enabled=true;
		eSkoreH->Enabled=true;
	}
	else {
		eSkoreD->Enabled=false;
		eSkoreH->Enabled=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TformBookmaker::btnNajdiZClick(TObject *Sender)
{
	if (eIdZ->Text!="") {
		TZapas *zap=(TZapas *)(SeznamZapasu->Najdi(StrToInt(eIdZ->Text)));
		if (zap!=NULL) {
			for (unsigned i = 0; i < (unsigned)SeznamZapasu->GetSeznam()->Count; i++) {
				TZapas *pom=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
				if (pom->IdZap==zap->IdZap) {
					libZapasy->ItemIndex=StrToInt(i);
					libZapasyClick(Sender);
					break;
				}
			}
		}
		else
			MessageDlg("Tiket s ID: "+(eIdZ->Text)+" nebyl nalezen!",mtInformation,TMsgDlgButtons() << mbOK,0);
	}         
	else
		MessageDlg("Musíte zadat nìjaké ID zápasu!!",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------

void __fastcall TformBookmaker::libZapasyClick(TObject *Sender)
{
	TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[libZapasy->ItemIndex]);
	eIdZ->Text=IntToStr(zap->IdZap);
	eVyhledanyZ->Text=IntToStr(zap->IdZap)+"	"+zap->JmenoD+"	"+zap->JmenoH;
	lbleJmenoD->Text=zap->JmenoD;
	lbleJmenoH->Text=zap->JmenoH;
	lbleKurzD->Text=FloatToStrF(zap->KurzD,ffFixed,15,2);
	lbleKurzRem->Text=FloatToStrF(zap->KurzRem,ffFixed,15,2);
	lbleKurzH->Text=FloatToStrF(zap->KurzH,ffFixed,15,2);
	dtpCas->Time=zap->CasZap;
	dtpDatum->Date=zap->DatZap;
	eSkoreD->Text=IntToStr(zap->SkoreD);
	eSkoreH->Text=IntToStr(zap->SkoreH);
	cboDohrano->Checked=(zap->Dohrano);
	if (zap->Dohrano)
		btnOdebratZ->Enabled=true;
	else
		btnOdebratZ->Enabled=false;
	for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
		TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (tip->IdZap==zap->IdZap) {
			btnOdebratZ->Enabled=false;
			break;
		}
		else
    	btnOdebratZ->Enabled=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TformBookmaker::libTiketyClick(TObject *Sender)
{
	TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[libTikety->ItemIndex]);
	lblDatTik->Caption=DateToStr(tik->DatTik);
	IdTiketu=tik->IdTik;
  eIdTiketu->Text=IntToStr(tik->IdTik);
	UkazSeznamZapasuTiketu();

	lblCKurz->Caption=FloatToStrF(tik->KurzTik,ffFixed,15,2);
	lbleCastka->Text=FloatToStrF(StrToFloat(tik->VkladTik)*1.1,ffFixed,15,2);
	lblCastkaVyhra->Caption=FloatToStrF(tik->VyhraTik,ffFixed,15,2);
	lbleVklad->Text=FloatToStrF(StrToFloat(tik->VkladTik),ffFixed,15,2);

	if (tik->Vyplaceno)
		lblVyhodnoceno->Caption="Ano";
	else
		lblVyhodnoceno->Caption="Ne";
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::libZapasyTiketuClick(TObject *Sender)
{
	try {
		TTip *tip;
		TZapas *zap;

		for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==IdTiketu) {
				tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i+libZapasyTiketu->ItemIndex]);
				break;
			}
		}
		 for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
				zap= (TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
				if (zap->IdZap==tip->IdZap) {
				lblJmenoDTik->Caption=zap->JmenoD;
				lblJmenoHTik->Caption=zap->JmenoH;
				lblDatZapTik->Caption=zap->DatZap;
				lblCasZapTik->Caption=zap->CasZap;
				eSD->Text=zap->SkoreD;
				eSH->Text=zap->SkoreH;
				if (zap->Dohrano) {
					if (tip->Vyhra)
						lblVyhraZap->Caption="ANO";
					else
						lblVyhraZap->Caption="NE";
					}
					else
						lblVyhraZap->Caption="Nedohráno";
				if (tip->Tip==1){
					lblVysTik->Caption="Výhru Domacích";
          lblKurzTip->Caption=FloatToStrF(zap->KurzD,ffFixed,15,2);
				}
				else if (tip->Tip==0){
					lblVysTik->Caption="Remízu";
					lblKurzTip->Caption=FloatToStrF(zap->KurzRem,ffFixed,15,2);
				}
				else {
					lblVysTik->Caption="Výhru Hostù";
					lblKurzTip->Caption=FloatToStrF(zap->KurzH,ffFixed,15,2);
				}
				break;
			}
		}
	}catch (...) {
		MessageDlg("Nastala neoèekávaná chyba v seznamu zápasù!",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnNajdiTiketClick(TObject *Sender)
{
	if (eIdTiketu->Text!="") {
		TTiket *tik=SeznamTiketu->Najdi(StrToInt(eIdTiketu->Text));
		if (tik!=NULL) {
			for (unsigned i = 0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
				TTiket *pom=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
				if (pom->IdTik==tik->IdTik) {
					libTikety->ItemIndex=StrToInt(i);
					libTiketyClick(Sender);
					break;
				}
			}
		}
		else
			MessageDlg("Tiket s ID: "+eIdTiketu->Text+" nebyl nalezen!",mtInformation,TMsgDlgButtons() << mbOK,0);
	}
	else
		MessageDlg("Musíte zadat nìjaké ID tiketu!!",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnSmazatTiketClick(TObject *Sender)
{
	try {
		if (libTikety->ItemIndex==-1)
    	throw "Nebyl vybrán žádný tiket!!";
		TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[libTikety->ItemIndex]);
		for (long int i = SeznamTipu->GetSeznam()->Count-1; i >=0; i--) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==tik->IdTik) {
				SeznamTipu->Zruseni(pom->IdTipu);
			}
		}     //Kdyz odstranim tiket odstranim i vsechny tipy na tento tiket
		SeznamTiketu->Zruseni(tik->IdTik);
		UkazSeznamTiketu();
	} catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	} catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}

}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnOdecistPenizeClick(TObject *Sender)
{           //Odecitani castky uzivateli
	try {
		if (libUzivatele->ItemIndex==-1)
    	throw "Nebyl vybrán žádný uživatel!!";
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[libUzivatele->ItemIndex]);
		long double castka=StrToFloat(lbleOdecistPenize->Text);
		if (castka<0)throw "Èástka musí být vìtší, než 0 !!!";
		if (castka>uziv->Konto)throw "Èástka musí být menší, než zùstatek na kontì !!!";
		uziv->Konto-=castka;
		lbleOdecistPenize->Text="";

    libUzivateleClick(Sender);
	} catch (char *chyba) {
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
		lbleOdecistPenize->Text="";
	} catch (...) {
		MessageDlg("Vyskytla se chyba v odeèítání penìz!",mtError,TMsgDlgButtons() << mbOK,0);
		lbleOdecistPenize->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnPricistPenizeClick(TObject *Sender)
{           //Pricitani castky uzivateli
	try {
		if (libUzivatele->ItemIndex==-1)
			throw "Nebyl vybrán žádný uživatel!!";
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[libUzivatele->ItemIndex]);
		long double castka=StrToFloat(lbleOdecistPenize->Text);
    if (castka<0)
			throw "Èástka musí být vìtší, než 0 !!!";
  
		uziv->Konto+=castka;
		lbleOdecistPenize->Text="";
    libUzivateleClick(Sender);
	}catch (char *chyba) {
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
		lbleOdecistPenize->Text="";
	}catch (...) {
		MessageDlg("Vyskytla se chyba v pøidávání penìz!",mtError,TMsgDlgButtons() << mbOK,0);
		lbleOdecistPenize->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::tsStatistikyShow(TObject *Sender)
{    //Statistika pro bookmakery
	try {
		unsigned pocet=0;
		lblePocetUzivatelu->Text=FloatToStr(SeznamUzivatelu->GetSeznam()->Count); 
		lblePocetBmakeru->Text=FloatToStr(SeznamBmakeru->GetSeznam()->Count);
		lblePocetZapasu->Text=FloatToStr(SeznamZapasu->GetSeznam()->Count);

		for (unsigned i = 0; i < (unsigned)SeznamZapasu->GetSeznam()->Count; i++) {
    	TZapas *zap = (TZapas*)(SeznamZapasu->GetSeznam()->Items[i]);
			if (zap->Dohrano)
				pocet++;
		}
		lblePocetDohZapasu->Text=IntToStr(pocet);
		lblePocetTipu->Text=FloatToStr(SeznamTipu->GetSeznam()->Count);

		pocet=0;
		for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
			TTip *tip = (TTip*)(SeznamTipu->GetSeznam()->Items[i]);
			if (tip->Vyhra)
				pocet++;
		}

		lblePocetSpravnychTipu->Text=IntToStr(pocet);

		long double castka= 0;
		for (unsigned i = 0; i < (unsigned)SeznamUzivatelu->GetSeznam()->Count; i++) {
			TUzivatel *uziv = (TUzivatel*)(SeznamUzivatelu->GetSeznam()->Items[i]);
    	castka+=uziv->Konto;
		}

		lblePenizeUzivatelu->Text=FloatToStrF(castka,ffFixed,15,2);

		pocet=0; //pocet tiketu
		long double vyhraneP= 0,prohraneP=0,vsazene=0; //Castky vyhranych, prohranych a vsazenych penez
		unsigned vyhraneT=0,prohraneT=0,nevyhodnoceneT=0; //Pocty vyhranych, prohranych a nevyhodnocenych tiketu
		for (unsigned i = 0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
			TTiket *tik = (TTiket*)(SeznamTiketu->GetSeznam()->Items[i]);
      pocet++;
			if (tik->Vyplaceno) {
				if (tik->VyhraTik==0) {
					prohraneP+=(tik->VkladTik*1.1);
        	prohraneT++;
				}
				else {
					vyhraneP+=tik->VyhraTik;
					vyhraneT++;
        }
			}
			else {
					nevyhodnoceneT++;
        	vsazene+=tik->VkladTik;
        }
		}

		lbleVydelanePenize->Text=FloatToStrF(vyhraneP,ffFixed,15,2);
		lbleProhranePenize->Text=FloatToStrF(prohraneP,ffFixed,15,2);
    lbleVsazenePenize->Text=FloatToStrF(vsazene,ffFixed,15,2);
		lblePocetTiketu->Text=IntToStr(pocet);
		lblePocetVyhTiketu->Text=IntToStr(vyhraneT);
		lblePocetProTiketu->Text=IntToStr(prohraneT);
  	lblePocetNevyhodnocenych->Text=IntToStr(nevyhodnoceneT);
	} catch (...) {
		MessageDlg("Vyskytla se chyba ve výpoètu statistiky",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::btnVyhodnotitZnovuClick(TObject *Sender)
{   //Po chybnem vyhodnoceni tiketu muze bookmaker vyhodnotit tiket znova, ale pokud byl vyhodnocen dobre, tak se
		//pricte vyhrana castka tiketu znova, pokud byla nenulova

 try {
	if (libTikety->ItemIndex==-1)
    	throw "Nebyl vybrán žádný tiket!!";
	TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[libTikety->ItemIndex]);
	int pocetZapasuTiketu=ZjistiPocetZapasuTiketu(tik->IdTik);

	for (int i = 0; i < SeznamTipu->GetSeznam()->Count; i++) {
		TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (tik->IdTik==tip->IdTik) {
			if (pocetZapasuTiketu>0) {
				TZapas *zap=(TZapas *)(SeznamZapasu->Najdi(tip->IdZap));
				if (zap->Dohrano) {
					if (!tip->Vyhra) {
						tik->VyhraTik=0;
						tik->Vyplaceno=true;
						break;
					}
					pocetZapasuTiketu--;
				}
			}
			if (pocetZapasuTiketu==0) {
				TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(tik->IdUziv));
				tik->VyhraTik=tik->VkladTik*tik->KurzTik;
				uziv->Konto+=tik->VyhraTik;
				tik->Vyplaceno=true;
			}
		}
	}
	} catch (char *chyba){
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
	} catch (...) {
		MessageDlg("Vyskytla se neoèekávaná chyba",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TformBookmaker::btnVyhodnotitZnovuEnter(TObject *Sender)
{
		MessageDlg("Mùže se stát, že pøipíšete uživateli znovu již pøipsanou výhru!!!",mtWarning,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------
void __fastcall TformBookmaker::lbleJmenoDExit(TObject *Sender)
{
	try {
		TLabeledEdit *pom=(TLabeledEdit *)Sender;
		pom->Text=pom->Text.Trim();
		String veta = pom->Text.Trim();
	} catch (...) {
		MessageDlg("Nìkde máte chybu, zkontrolujte údaje!!",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_uzivatel.h"

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
TformUzivatel *formUzivatel;
//---------------------------------------------------------------------------
__fastcall TformUzivatel::TformUzivatel(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::FormShow(TObject *Sender)
{
	formPrihlaseni->Hide(); //ukryju hlavni okno
	pcUzivatel->TabIndex=0;  //pri stousteni se mi zapne prvni(nulta) zalozka v pagecontrolu
	PosledniIdTiketu=SeznamTiketu->DejPosledniKlic()+1;  //Musím udìlat tiket pro vytvoøení, když nevsadím smažu ho ve FormClose();
	UkazSeznamZapasu();         //vypisu seznamy do listu
	UkazSeznamTipu();       //Vypisu seznam tipu, ale nemelo by tam nic byt
	UkazCelkovyKurz();      //Spocitam/Ukazu celkovy kurz, ale nemel bych mit zadny tip takze 1
	UkazSeznamTiketuUzivatele(); //Vypisu Seznam tiketu uzivatele
	//ShowMessage(sizeof(TTip));
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::FormClose(TObject *Sender, TCloseAction &Action)
{
	for (long int i = (SeznamTipu->GetSeznam()->Count-1); i >= 0; i--) { //prochazim seznam tipu od zadu, protoze
		TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);  //kdyz smazu nejakou polozku pri hledani zepredu, tak se mi cely seznam
		if (pom->IdTik==PosledniIdTiketu) { //posune, tak musim delat od zadu. Promazu vsechny tipy u posledniho tiketu.
			SeznamTipu->Zruseni(pom->IdTipu);
		}
	}
	SeznamTiketu->Zruseni(PosledniIdTiketu); //Radeji smazu tiket, kdyby se vyskytla nejaka chyba
	formPrihlaseni->Close();    //Uzavru hlavni okno a ukoncim app
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::UkazCelkovyKurz()
{
	CelkovyKurzT=1;     //nastavim celkovy kurz na 1 abych si byl jisty o jeho hodnote
	for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {    //prochazim seznam tipu a hledam ID tiketu
		TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);          //stejne jako Posledni ID Tiketu a kdyz ho
		if (tip->IdTik==PosledniIdTiketu) {                            //najdu tak prohledam vsechny zapasy a najdu
			for (unsigned j = 0; j < (unsigned)SeznamZapasu->GetSeznam()->Count; j++) {   // si odpovidajici zapas v seznamuZap
				TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[j]);    //pak si vypoctu Celkovy kurz
				if (zap->IdZap==tip->IdZap) {
					if (tip->Tip==1)
						CelkovyKurzT*=zap->KurzD;
					else if (tip->Tip==0)
						CelkovyKurzT*=zap->KurzRem;             //vynasobim celkovy kurz dalsim kurzem dalsiho tipu
					else
						CelkovyKurzT*=zap->KurzH;
					break;
				}
			}
		}
	}
	if (StrToFloat(lbleVklad->Text)*CelkovyKurzT!=StrToFloat(lbleVklad->Text))
		lblCastkaVyhra->Caption=FloatToStrF(StrToFloat(lbleVklad->Text)*CelkovyKurzT,ffFixed,15,2);
	else
		lblCastkaVyhra->Caption=IntToStr(0);

	lblCKurz->Caption=FloatToStrF(CelkovyKurzT,ffFixed,15,2);
	lbleCastka->Text=FloatToStrF(StrToFloat(lbleVklad->Text)*1.1,ffFixed,15,2);
}
//---------------------------------------------------------------------------
void __fastcall  TformUzivatel::UkazSeznamZapasu()
{
	libZapasy->Clear();  //promazu listbox
	for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) { //projdu seznam zapasu
		TZapas *zap=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]); //ukazatele na jednotlive polozky v seznamu
		if ((zap->DatZap>=Date())&&(!zap->Dohrano)) //jestli datum zapasu je mensi a zapas je dohran nezobrazim ho
			libZapasy->Items->Add(IntToStr(zap->IdZap)+"	"+zap->JmenoD+"	"+zap->JmenoH+"	"+zap->DatZap);
	}         //pridam do listboxu polozky
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::UkazSeznamTipu()
{
	libTiket->Clear();
	for (int i = 0; i < SeznamTipu->GetSeznam()->Count; i++) {
		TTip *tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (tip->IdTik==PosledniIdTiketu) //jestli je posledni id tiketu rovno idtiketu tipu tak jej zobrazim
			libTiket->Items->Add("ID Tipu:  "+IntToStr(tip->IdTipu)+"	ID Zapasu:  "+IntToStr(tip->IdZap)+"		ID Tiketu:  "+IntToStr(tip->IdTik)+"		Tip:  "+IntToStr(tip->Tip));
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::UkazSeznamTiketuUzivatele()
{
	libTikety->Clear();
	for (int i = 0; i < SeznamTiketu->GetSeznam()->Count; i++) {
		TTiket *tik=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
		if ((tik->IdUziv)==IdUzivatele) //jestli je id uzivatele(z prihlaseni) rovno tiketu tak jej zobrazim
			libTikety->Items->Add("ID Tiketu:	"+IntToStr(tik->IdTik)+"	ID Uzivatele:	"+IntToStr(tik->IdUziv)+"	"+DateToStr(tik->DatTik));
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::UkazSeznamZapasuTiketu()
{
	libZapasyTiketu->Clear();
	for (int i = 0; i < SeznamTipu->GetSeznam()->Count; i++) {
		TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
		if (pom->IdTik==IdTiketu) {
			TZapas *zap=SeznamZapasu->Najdi(pom->IdZap);
			if (zap==NULL)continue;
			if (pom->IdZap==zap->IdZap)
				libZapasyTiketu->Items->Add("È. Tipu:	"+IntToStr(pom->IdTipu)+"	Domaci:	"+zap->JmenoD+"	Hoste:	"+zap->JmenoH);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::UkazStatistiky()
{
	int pocTiketu=0,pocTipu=0;  //pocty spravnych tipu a tiketu
	unsigned cPocTik=0,cPocTip=0;   //pocty vsech tipu a tiketu
	for (unsigned i = 0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
		TTiket *tiket=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
		if (tiket->IdUziv==IdUzivatele) {
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
void __fastcall TformUzivatel::libZapasyClick(TObject *Sender)
{                              //kliknuti na listbox zapasy v moznostech sazek
	gboZapas->Visible=true;      //Odkryju groupbox zapas kde jsou jednotlive kurzy a moznosti sazkek na zapas
	try {
		TZapas *zap;
		for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
			TZapas *pom=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
			if ((pom->DatZap>=Date())&&(!pom->Dohrano)) {
				zap= (TZapas *)(SeznamZapasu->GetSeznam()->Items[i+libZapasy->ItemIndex]); //prictu listboxzapasy->itemindex
				break;                                    //abych se dostal k polozce kterou hledam 
			}
		}
		//Vypis ze seznamu do komponent (moznost zmeny)
		lblJmenoD->Caption=zap->JmenoD;
		lblJmenoH->Caption=zap->JmenoH;
		lblDatZap->Caption=zap->DatZap;  //generovalo vyjimku pouze pro mne protoze nektere data jsou mensi nez mindate, upravil jsem mindate jak pridavam zapas
		lblCasZap->Caption=zap->CasZap;
		btnPridatD->Caption=FloatToStrF(zap->KurzD,ffFixed,15,2);
		btnPridatR->Caption=FloatToStrF(zap->KurzRem,ffFixed,15,2);
		btnPridatH->Caption=FloatToStrF(zap->KurzH,ffFixed,15,2);
	}
	catch (...) {
	}	
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnPridatDClick(TObject *Sender)
{
	try {
		if (libZapasy->ItemIndex==-1)throw "Není vybrán žadný zápas!";
			gboTiket->Visible=true;
		int vybranyTip;
		TButton *btn=(TButton*)Sender;
		switch(btn->Tag){
			case 0: vybranyTip=0;
				break;
			case 1: vybranyTip=1;
				break;
			case 2: vybranyTip=2;
		}
		TZapas *zap=NULL;
		for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
			TZapas *pom=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
			if ((pom->DatZap>=Date())&&(!pom->Dohrano)) {
				zap= (TZapas *)(SeznamZapasu->GetSeznam()->Items[i+libZapasy->ItemIndex]);
				for (unsigned j = 0; j < (unsigned)SeznamTipu->GetSeznam()->Count; j++) {
					TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[j]);
					//ShowMessage(IdTiketu);
					if (pom->IdTik==PosledniIdTiketu) {
						if (pom->IdZap==zap->IdZap) {
            	throw "Nelze sázet na jeden zápas více než 1x!!!";
						}
					}
				}
				break;
			}
		}
		if (vybranyTip==0) {
			TTip tip(SeznamTipu->DejPosledniKlic(),zap->IdZap,PosledniIdTiketu,vybranyTip,false);// Udelam pomocnou promennou pom typu TTIP
			SeznamTipu->Pridani(tip);
		}
		if (vybranyTip==1){
			TTip tip(SeznamTipu->DejPosledniKlic(),zap->IdZap,PosledniIdTiketu,vybranyTip,false);// Udelam pomocnou promennou pom typu TTIP
			SeznamTipu->Pridani(tip);
		}
		if (vybranyTip==2){
			TTip tip(SeznamTipu->DejPosledniKlic(),zap->IdZap,PosledniIdTiketu,vybranyTip,false);// Udelam pomocnou promennou pom typu TTIP
			SeznamTipu->Pridani(tip);
		}      
		UkazSeznamTipu();
		UkazCelkovyKurz();              //vypisu seznamy do list
		UkazSeznamTiketuUzivatele();
	}
	catch (char *chyba) {
		ShowMessage(chyba);
	}
	catch (...) {
		ShowMessage("Vyskytla se chyba v pøidávání sázky!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::libTiketClick(TObject *Sender)
{
	try {
		TTip *tip;
		TZapas *zap;

		for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==PosledniIdTiketu) {
				tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i+libTiket->ItemIndex]);
				break;
			}
		}
		 //ShowMessage(tip->IdZap);
		 for (int i = 0; i < SeznamZapasu->GetSeznam()->Count; i++) {
			TZapas *pom=(TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
			if ((pom->DatZap>=Date())&&(!pom->Dohrano)) {
				zap= (TZapas *)(SeznamZapasu->GetSeznam()->Items[i]);
				if (zap->IdZap==tip->IdZap) {
				//Vypis ze seznamu do poli (moznost zmeny)
				lblJmenoDTik->Caption=zap->JmenoD;
				lblJmenoHTik->Caption=zap->JmenoH;
				lblDatZapTik->Caption=zap->DatZap;  //generovalo vyjimku pouze pro mne protoze nektere data jsou mensi nez mindate, upravil jsem mindate jak pridavam zapas
				lblCasZapTik->Caption=zap->CasZap;
				if (tip->Tip==1){
					lblVysTik->Caption="Výhru Domacích";
					lblKurzTik->Caption=FloatToStrF(zap->KurzD,ffFixed,15,2);
				}
				else if (tip->Tip==0){
					lblVysTik->Caption="Remízu";
					lblKurzTik->Caption=FloatToStrF(zap->KurzRem,ffFixed,15,2);
				}
				else {
					lblVysTik->Caption="Výhru Hostù";
					lblKurzTik->Caption=FloatToStrF(zap->KurzH,ffFixed,15,2);
				}
				break;
				}
			}
		}
	}
	catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::bbtnOdebratZTikClick(TObject *Sender)
{
	try {
		TTip *tip;
		TZapas *zap;
		for (unsigned i = 0; i < (unsigned)SeznamTipu->GetSeznam()->Count; i++) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==PosledniIdTiketu) {
				tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i+libTiket->ItemIndex]);
				break;
			}
		}
		SeznamTipu->Zruseni(tip->IdTipu);  //odeberu tip ktery jsem chtel

		UkazSeznamTipu();                //vypisu seznamy do listu
		UkazCelkovyKurz();
	}
	catch (...) {
  	ShowMessage("Nastala chyba pøi odebírání zápasu!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::bbtnVsaditClick(TObject *Sender)
{
	try {
    TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		if (StrToFloat(lbleVklad->Text)<20)throw "Minimální vklad musí být minimálnì 20,-KÈ";
		if (StrToFloat(lbleVklad->Text)>uziv->Konto)throw "Nemáte dostatek penìz!!!!!";
		if (StrToFloat(lbleVklad->Text)<0)throw "Špatnì zadaná èástka!!";
    int j=0;
		for (int i = 0; i < SeznamTipu->GetSeznam()->Count; i++) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==PosledniIdTiketu)
      	j++;
		}
		if (j<2)throw "Sázíté na málo zápasù!";
		TTiket tiket(PosledniIdTiketu+1,IdUzivatele,CelkovyKurzT,StrToFloat(lbleVklad->Text),
								StrToFloat(lblCastkaVyhra->Caption),Date(),false);
																//vytvorim tiket z udaju
		SeznamTiketu->Pridani(tiket); //pridam tiket do seznamu
		uziv->Konto-=StrToFloat(lbleVklad->Text); //odectu vsazene penize
		PosledniIdTiketu++;           //Zvysim udaj o posledni id

		UkazSeznamTipu();             //vypisu seznamy do listu
		UkazCelkovyKurz();
		UkazSeznamTiketuUzivatele();

	}catch (char *chyba) {
  	ShowMessage(chyba);
	}catch (...) {
		ShowMessage("Nastala chyba pøi podávání tiketu!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnPrepocitatClick(TObject *Sender)
{
	UkazCelkovyKurz();	  //Ukaze celkovy kurz
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::libTiketyClick(TObject *Sender)
{

	int poziceCyklu=0;   //Zacatek cyklu->Pozice tiketu od konkretniho uziv
	int poziceTiketu=libTikety->ItemIndex; //pozice tiketu v listu
	for (int i = 0; i < SeznamTiketu->GetSeznam()->Count; i++) {  //prochazeni seznamu tiketu
		TTiket *pom=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);  // vytvareni konkretniho tiketu s IdTik = i;
		if ((pom->IdUziv)==IdUzivatele){  //kontrola jestli tiket je od prihlaseneho uzivatele
			if (poziceTiketu==poziceCyklu) {   //kontrola, jestli se uz nedoslo na vybranou polozku v listu
				IdTiketu=pom->IdTik;    //prepsani id tiketu !! potrebne k vykresleni zapasu!!
				//ShowMessage(pom->VyhraTik);
				break;
												//cyklus nasel id a muze skoncit
			}
			poziceCyklu++;   //poziciCyklu posouvam smerem k pozici vybrane polozky v listu
		}
	}

	TTiket *tik=SeznamTiketu->Najdi(IdTiketu); //Najdu v seznamu tiket s IdTiketu
	eIdTiketu->Text=IntToStr(tik->IdTik);

  if (tik->Vyplaceno)
		lblVyhodnoceno->Caption="Ano";
	else
		lblVyhodnoceno->Caption="Ne";
	lblDatTik->Caption=DateToStr(tik->DatTik);
	lblCKurz2->Caption=FloatToStrF(tik->KurzTik,ffFixed,15,2);
	lbleCastka2->Text=FloatToStrF(StrToFloat(tik->VkladTik)*1.1,ffFixed,15,2);
	lblCastkaVyhra2->Caption=FloatToStrF(tik->VyhraTik,ffFixed,15,2);
	lbleVklad2->Text=FloatToStrF(StrToFloat(tik->VkladTik),ffFixed,15,2);

	UkazSeznamZapasuTiketu();
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::libZapasyTiketuClick(TObject *Sender)
{
	try {
		//TTiket *tik=SeznamTiketu->Najdi(IdTiketu);
		TTip *tip;
		TZapas *zap;
		for (int i = 0; i < SeznamTipu->GetSeznam()->Count; i++) {
			TTip *pom=(TTip *)(SeznamTipu->GetSeznam()->Items[i]);
			if (pom->IdTik==IdTiketu) {
				tip=(TTip *)(SeznamTipu->GetSeznam()->Items[i+libZapasyTiketu->ItemIndex]);
				zap=SeznamZapasu->Najdi(tip->IdZap);
				if (zap==NULL)continue;
				break;
			}
		}
					eSkoreD->Text=zap->SkoreD;
					eSkoreH->Text=zap->SkoreH;
					lblJmenoDTik2->Caption=zap->JmenoD;
					lblJmenoHTik2->Caption=zap->JmenoH;
					lblDatZapTik2->Caption=zap->DatZap;  //generovalo vyjimku pouze pro mne protoze nektere data jsou mensi nez mindate, upravil jsem mindate jak pridavam zapas
					lblCasZapTik2->Caption=zap->CasZap;
					if (tip->Tip==1){
						lblVysTik2->Caption="Výhru Domacích";
						lblKurzTik2->Caption=FloatToStrF(zap->KurzD,ffFixed,15,2);
					}
					else if (tip->Tip==0){
						lblVysTik2->Caption="Remízu";
						lblKurzTik2->Caption=FloatToStrF(zap->KurzRem,ffFixed,15,2);
					}
					else {
						lblVysTik2->Caption="Výhru Hostù";
						lblKurzTik2->Caption=FloatToStrF(zap->KurzH,ffFixed,15,2);
					}
					if (zap->Dohrano) {
						if (tip->Vyhra){
							lblVyhraZap->Caption="ANO";
						}
						else
							lblVyhraZap->Caption="NE";
					}
					else lblVyhraZap->Caption="Nedohráno";
	}
	catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::tsKontoShow(TObject *Sender)
{
	try {
    UkazStatistiky();
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		lbleZustatek->Text=FloatToStrF(uziv->Konto,ffFixed,15,2)+" ,-KÈ";
	} catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnPridatPenizeClick(TObject *Sender)
{
	float castka=0;
	try {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		castka=StrToFloat(lblePridatPenize->Text);
		if (castka<0)throw "Èástka musí být vìtší, než 0 !!!";
		uziv->Konto+=castka;
		tsKontoShow(Sender);
		lblePridatPenize->Text="";
	}catch (char *chyba) {
		ShowMessage(chyba);
		lblePridatPenize->Text="";
	}catch (...) {
		ShowMessage("Vyskytla se chyba v pøidávání penìz!");
		lblePridatPenize->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnVybratPenizeClick(TObject *Sender)
{
	try {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		long double castka=StrToFloat(lbleVybratPenize->Text);
		if (castka<0)throw "Èástka musí být vìtší, než 0 !!!";
		if (castka>uziv->Konto)throw "Èástka musí být menší, než Váš zùstatek na kontì !!!";
		uziv->Konto-=castka;
		tsKontoShow(Sender);
		lbleVybratPenize->Text="";
	}catch (char *chyba) {
		ShowMessage(chyba);
		lbleVybratPenize->Text="";
	}catch (...) {
		ShowMessage("Vyskytla se chyba v pøidávání penìz!");
		lbleVybratPenize->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnNajdiTiketClick(TObject *Sender)
{
	try {
 		TTiket *tiket=(TTiket *)(SeznamTiketu->Najdi(StrToInt(eIdTiketu->Text)));
		if (tiket->IdUziv==IdUzivatele){
			unsigned poc = 0;  //pocet kdy cyklus prosel podminkou o rovnosti Iduzivatele a tik->IDU
			for (unsigned i = 0; i < (unsigned)SeznamTiketu->GetSeznam()->Count; i++) {
				TTiket *pom=(TTiket *)(SeznamTiketu->GetSeznam()->Items[i]);
				if (pom->IdUziv==IdUzivatele){
					if (pom->IdTik==tiket->IdTik) {
						libTikety->ItemIndex=poc;
						libTiketyClick(Sender);
					}
					poc++;
				}
			}
		}
		else
			throw "Tiket nebyl nalezen!";
	} catch (char *chyba) {
		ShowMessage(chyba);
	} catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::tsProfilShow(TObject *Sender)
{
	TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
	lbleMesto->Text=uziv->Mesto;
	lbleUlice->Text=uziv->Adresa;
	lbleCisPop->Text=IntToStr(uziv->CisPop);
	lblePSC->Text=uziv->PSC;
	lbleTelCis->Text=uziv->TelCis;
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnZmenUdajeClick(TObject *Sender)
{
	try {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		if (lbleUlice->Text=="" || lbleCisPop->Text=="" || lbleMesto->Text=="" ||
				lblePSC->Text=="" || lbleTelCis->Text=="")
			throw "Zkontrolujte své údaje";
		if (lbleUlice->Text.Length()<3 || lbleMesto->Text.Length()<1 ||
				lblePSC->Text.Length()<4 ||  lbleTelCis->Text.Length()<8)
			throw "Údaje musí mít více než 3 znaky!(Email více než 5, mìsto více než 1, telefon více než 8, PSÈ více než 4)";

		unsigned short d,m,r;
		DecodeDate(uziv->DatNar,r,m,d);  //Dekoduju datum narozeni od uzivatele

		uziv->UpravLog(uziv->Jmeno,uziv->Prijmeni,uziv->Heslo,uziv->Email,d,m,r,lbleMesto->Text.Trim(),
		lbleUlice->Text.Trim(),StrToInt(lbleCisPop->Text.Trim()),StrToInt(lblePSC->Text.Trim()),lbleTelCis->Text.Trim());
	} catch (char *chyba) {
		ShowMessage(chyba);
	} catch (...) {
	}
}
//---------------------------------------------------------------------------
void __fastcall TformUzivatel::btnZmenHesloClick(TObject *Sender)
{
	try {
		TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->Najdi(IdUzivatele));
		if (lbleStareHeslo->Text=="" || lbleHeslo1->Text=="" || lbleHeslo2->Text=="" )
			throw "Není vyplnìné nìkteré z hesel";
		if ((lbleHeslo1->Text!=lbleHeslo2->Text)||(lbleHeslo1->Text.Length()<=5))
			throw "Vámi zadaná hesla se neshodují nebo jsou krátké (Musí být zadáno minimálnì 6 a více znakù)";
		if (lbleStareHeslo->Text!=uziv->Heslo)
			throw "Staré hesla se neshodují";
    
		unsigned short d,m,r;
		DecodeDate(uziv->DatNar,r,m,d);  //Dekoduju datum narozeni od uzivatele

		uziv->UpravLog(uziv->Jmeno,uziv->Prijmeni,lbleHeslo1->Text,uziv->Email,d,m,r,
		lbleMesto->Text.Trim(),uziv->Adresa,uziv->CisPop,uziv->PSC,uziv->TelCis);

    lbleStareHeslo->Clear();
		lbleHeslo1->Clear();
		lbleHeslo2->Clear();
	} catch (char *chyba) {
		ShowMessage(chyba);
	} catch (...) {
	}
}
//---------------------------------------------------------------------------


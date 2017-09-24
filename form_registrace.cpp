//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include <memory>
#include <DateUtils.hpp>
#pragma hdrstop

#include "Bookmakeri.h"
#include "Hraci.h"
#include "form_registrace.h"
#include "form_prihlaseni.h"
#include "form_bookmaker.h"
#include "form_uzivatel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformRegistrace *formRegistrace;
//---------------------------------------------------------------------------
__fastcall TformRegistrace::TformRegistrace(TComponent* Owner)	: TForm(Owner)
{
	if (SeznamBmakeru->GetSeznam()->Count==0) {  //Zajisti registraci bookmakera kdyz zadny neni
		btnRegistrovat->Tag=3;   //tim se zajisti aspon jeden spravce (logicky pri prvnim spusteni app
	}     											// nebo smazani seznamu bmakeru)
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::FormShow(TObject *Sender)
{
	for (int i = 1; i <= 31; i++)    //Pro zacatek 31 dni, protoze je nastaven Leden
		cboDenNar->Items->Add(i);
	for (int i = 1; i <= 12; i++)
		cboMesNar->Items->Add(i);
	cboMesNar->ItemIndex=0;   //Nastavení Ledna
	for (int i = (YearOf(Date())); i >= CurrentYear()-100  ; i--)
		cboRokNar->Items->Add(i);
	cboRokNar->ItemIndex=18;   //Nastavení roku
	try {
		if (btnRegistrovat->Tag==1) {
			int index =formBookmaker->libUzivatele->ItemIndex; //z formBo.. si najdu index
			if (index!=-1) {    //protoze jsem zvolil upravu uzivatele
				lbleEmail->Enabled=false; //zrusim moznost prepsani emailu
				TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[index]);
				lbleJmeno->Text=uziv->Jmeno;
				lblePrijmeni->Text=uziv->Prijmeni;
				unsigned short d,m,r;
				DecodeDate(uziv->DatNar,r,m,d);
				cboDenNar->Text=d;
				cboMesNar->Text=m;
				cboRokNar->Text=r;         //Vsechny informace o uziv pretahnu do poli
				lbleEmail->Text=uziv->Email;
				lbleHeslo1->Text=uziv->Heslo;
				lbleHeslo2->Text=uziv->Heslo;
				lbleMesto->Text=uziv->Mesto;
				lbleAdresa->Text=uziv->Adresa;
				lbleCisPop->Text=uziv->CisPop;
				lblePSC->Text=uziv->PSC;
				lbleTelCis->Text=uziv->TelCis;
				chboPodminky->Checked=true;
				btnRegistrovat->Enabled=true;
				btnRegistrovat->Caption="Uprav";
			}
		}
		else if (btnRegistrovat->Tag==2) {
			int index =formBookmaker->libBmakeri->ItemIndex;//z formBo.. si najdu index
			if (index!=-1) {    //protoze jsem zvolil upravu bookmakera
				lbleEmail->Enabled=false;
				TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[index]);
				lbleJmeno->Text=bmk->Jmeno;
				lblePrijmeni->Text=bmk->Prijmeni;
				unsigned short d,m,r;
				DecodeDate(bmk->DatNar,r,m,d);
				cboDenNar->Text=d;
				cboMesNar->Text=m;
				cboRokNar->Text=r;    //Vsechny informace o bmk pretahnu do poli
				lbleEmail->Text=bmk->Email;
				lbleHeslo1->Text=bmk->Heslo;
				lbleHeslo2->Text=bmk->Heslo;
				lbleMesto->Text=bmk->Mesto;
				lbleAdresa->Text=bmk->Adresa;
				lbleCisPop->Text=bmk->CisPop;
				lblePSC->Text=bmk->PSC;
				lbleTelCis->Text="6961961";
				chboPodminky->Checked=true;
				btnRegistrovat->Enabled=true;
				btnRegistrovat->Caption="Uprav";
			}
		}
			else {
        lbleEmail->Enabled=true;
				lbleJmeno->Text="";
				lblePrijmeni->Text="";
				cboDenNar->Text="";
				cboMesNar->Text="";
				cboRokNar->Text="";
				lbleEmail->Text="";
				lbleHeslo1->Text="";
				lbleHeslo2->Text="";
				lbleMesto->Text="";
				lbleAdresa->Text="";
				lbleCisPop->Text="";
				lblePSC->Text="";
				lbleTelCis->Text="";
				chboPodminky->Checked=false;
				btnRegistrovat->Enabled=false;
				btnRegistrovat->Caption="REGISTROVAT";
			}
	} catch (...) {
		ShowMessage("Nastala chyba ve pøidávání, nebo úpravì bookmakera");
	}
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::FormClose(TObject *Sender,TCloseAction &Action)
{
	lbleJmeno->Text="";
	lblePrijmeni->Text="";
	cboDenNar->Text="";
	cboMesNar->Text="";
	cboRokNar->Text="";
	lbleEmail->Text="";
	lbleHeslo1->Text="";
	lbleHeslo2->Text="";
	lbleMesto->Text="";
	lbleAdresa->Text="";
	lbleCisPop->Text="";
	lblePSC->Text="";
	lbleTelCis->Text="";
	chboPodminky->Checked=false;
	btnRegistrovat->Enabled=false;
	btnRegistrovat->Tag=0;
	btnRegistrovat->Caption="REGISTROVAT";
	lbleEmail->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::btnRegistrovatClick(TObject *Sender)
{
	try{
		if (lbleJmeno->Text==""||lblePrijmeni->Text==""||lbleAdresa->Text==""||lbleCisPop->Text==""||
			lbleEmail->Text==""||lbleHeslo1->Text==""||lbleHeslo2->Text==""||lbleMesto->Text==""||
			lblePSC->Text==""||lbleTelCis->Text=="")
				throw "Nìkde nemáte zadané údaje. (Všechny údaje jsou povinné!)";  //Osetreni prazdnych poli
		if ((!AnsiContainsText(lbleEmail->Text,"@"))||(!AnsiContainsText(lbleEmail->Text,".")))
      	throw "Špatnì zadaný email";
		if (lbleJmeno->Text.Length()<3||lblePrijmeni->Text.Length()<3||lbleAdresa->Text.Length()<3||
			lbleEmail->Text.Length()<5||lbleMesto->Text.Length()<1||lblePSC->Text.Length()<4||lbleTelCis->Text.Length()<8)
			throw "Údaje musí mít více než 3 znaky!(Email více než 5, mìsto více než 1, telefon více než 8, PSÈ více než 4)";
			 //Osetreni delky textu v polich
		TDateTime datNar = TDateTime(StrToInt(cboRokNar->Text),StrToInt(cboMesNar->Text),StrToInt(cboDenNar->Text));
			 //Osetreni veku
		if (YearsBetween(Now(),datNar)<18)
			throw "Nejste plnoletý/á";
		if ((lbleHeslo1->Text.Trim()!=lbleHeslo2->Text.Trim())||(lbleHeslo1->Text.Trim().Length()<=5)) //osetreni hesla
			throw "Vámi zadaná hesla se neshodují nebo jsou krátké (Musí být zadáno minimálnì 6 a více znakù)";

		//pridani uzivatele
		if (btnRegistrovat->Tag==0) {
			for (unsigned i = 0; i < (unsigned)SeznamUzivatelu->GetSeznam()->Count; i++) {
				if ((SeznamUzivatelu->GetSeznam()->Items[i])!=NULL) {
					TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
					if (lbleEmail->Text.Trim()==uziv->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			}
			for (unsigned i = 0; i < (unsigned)SeznamBmakeru->GetSeznam()->Count; i++) {
				if ((SeznamBmakeru->GetSeznam()->Items[i])!=0) {
					TBmaker *pom=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
					if (lbleEmail->Text.Trim()==pom->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			} //zkontrolovani jestli se email neopakuje
			TUzivatel uziv(SeznamUzivatelu->DejPosledniKlic(),lbleJmeno->Text.Trim(),lblePrijmeni->Text.Trim(),
				lbleHeslo1->Text.Trim(),lbleEmail->Text.Trim(),StrToInt(cboDenNar->Text),StrToInt(cboMesNar->Text),StrToInt(cboRokNar->Text),
				lbleMesto->Text.Trim(),lbleAdresa->Text.Trim(),StrToInt(lbleCisPop->Text),lblePSC->Text.Trim(),
				lbleTelCis->Text.Trim(),0);
			SeznamUzivatelu->Pridani(uziv);
		}

		//uprava bookmakera
		else if (btnRegistrovat->Tag==2) {
			TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[formBookmaker->libBmakeri->ItemIndex]);
			for (unsigned i = 0; i < (unsigned)SeznamBmakeru->GetSeznam()->Count; i++) {
				if ((SeznamBmakeru->GetSeznam()->Items[i])!=0) {
					TBmaker *pom=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
					if (bmk->Email==pom->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			}
			for (unsigned i = 0; i < (unsigned)SeznamUzivatelu->GetSeznam()->Count; i++) {
					if ((SeznamUzivatelu->GetSeznam()->Items[i])!=NULL) {
						TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
						if (bmk->Email==uziv->Email) {
							throw "Vámi zadaný email je již používán";
						}
					}
			} //zkontrolovani jestli se email neopakuje
			bmk->UpravLog(lbleJmeno->Text.Trim(),lblePrijmeni->Text.Trim(),
				lbleHeslo1->Text.Trim(),lbleEmail->Text.Trim(),StrToInt(cboDenNar->Text),StrToInt(cboMesNar->Text),StrToInt(cboRokNar->Text),
				lbleMesto->Text.Trim(),lbleAdresa->Text.Trim(),StrToInt(lbleCisPop->Text),StrToInt(lblePSC->Text),
				lbleTelCis->Text.Trim()) ;
		}

  	//uprava uzivatele
		else if (btnRegistrovat->Tag==1) {
			TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[formBookmaker->libUzivatele->ItemIndex]);
			for (int i = 0; i < SeznamUzivatelu->GetSeznam()->Count; i++) {
				if ((SeznamBmakeru->GetSeznam()->Items[i])!=0) {
					TUzivatel *pom=(TUzivatel *)(SeznamBmakeru->GetSeznam()->Items[i]);
					if (uziv->Email==pom->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			}
			for (unsigned i = 0; i < (unsigned)SeznamBmakeru->GetSeznam()->Count; i++) {
				if ((SeznamBmakeru->GetSeznam()->Items[i])!=0) {
					TBmaker *pom=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
					if (uziv->Email==pom->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			}  //zkontrolovani jestli se email neopakuje
			uziv->UpravLog(lbleJmeno->Text.Trim(),lblePrijmeni->Text.Trim(),
				lbleHeslo1->Text.Trim(),lbleEmail->Text.Trim(),StrToInt(cboDenNar->Text),StrToInt(cboMesNar->Text),StrToInt(cboRokNar->Text),
				lbleMesto->Text.Trim(),lbleAdresa->Text.Trim(),StrToInt(lbleCisPop->Text),StrToInt(lblePSC->Text),
				lbleTelCis->Text.Trim());
		}

		//pridani bookmakera
		else if (btnRegistrovat->Tag==3) {
				//TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[formBookmaker->libBmakeri->ItemIndex]);
			for (int i = 0; i < SeznamBmakeru->GetSeznam()->Count; i++) {
				if ((SeznamBmakeru->GetSeznam()->Items[i])!=0) {
					TBmaker *pom=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
					if (lbleEmail->Text.Trim()==pom->Email) {
						throw "Vámi zadaný email je již používán";
					}
				}
			}
			for (unsigned i = 0; i < (unsigned)SeznamUzivatelu->GetSeznam()->Count; i++) {
					if ((SeznamUzivatelu->GetSeznam()->Items[i])!=NULL) {
						TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
						if (lbleEmail->Text.Trim()==uziv->Email) {
							throw "Vámi zadaný email je již používán";
						}
					}
			}  //zkontrolovani jestli se email neopakuje
			TBmaker bmk(SeznamBmakeru->DejPosledniKlic(),lbleJmeno->Text.Trim(),lblePrijmeni->Text.Trim(),
				lbleHeslo1->Text.Trim(),lbleEmail->Text.Trim(),StrToInt(cboDenNar->Text),StrToInt(cboMesNar->Text),StrToInt(cboRokNar->Text),
				lbleMesto->Text.Trim(),lbleAdresa->Text.Trim(),StrToInt(lbleCisPop->Text),StrToInt(lblePSC->Text),
				lbleTelCis->Text.Trim());
			SeznamBmakeru->Pridani(bmk);
		}
	} catch(char *chyba) {
		MessageDlg(chyba,mtError,TMsgDlgButtons() << mbOK,0);
		ModalResult=mrNone;
	} catch(...) {
		MessageDlg("Nìkde máte chybu, zkontrolujte si své údaje!!",mtError,TMsgDlgButtons() << mbOK,0);
		ModalResult=mrNone;
	}
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::cboMesNarChange(TObject *Sender)
{
	cboDenNar->Clear();   //Systemove osetreni dnu v mesici a roce
	for (int i = 1; i <= DaysInAMonth(StrToInt(cboRokNar->Items->Strings[cboRokNar->ItemIndex]),cboMesNar->ItemIndex+1); i++)
		cboDenNar->Items->Add(i);
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::lbleJmenoExit(TObject *Sender)
{
	try {       //Osetreni zadavani mezer a jinych znaku
		TLabeledEdit *pom=(TLabeledEdit *)Sender;
		pom->Text=pom->Text.Trim();
		String veta = pom->Text.Trim();

		int pocet = veta.Length();
		int pctMezer = 0;
		bool mezeryZasebou = false;

		if ((pom->Name!="lbleMesto")&&(pom->Name!="lbleAdresa")) {
			if (AnsiContainsText(veta," ")) {
				throw "Nesmí obsahovat mezery!!";
			}
		}
		for (int i = 1; i <= pocet; i++, mezeryZasebou=false) {
			if ((veta[i]>=0)&&(veta[i]<=64))throw "Pouze písmena abecedy";
			if ((pom->Name=="lbleMesto")||(pom->Name=="lbleAdresa")) {
				if (AnsiCompareText(veta[i]," ")==0) {
					pctMezer++;
					if (AnsiCompareText(veta[i-1]," ")==0)
						mezeryZasebou=true;
					if ((pctMezer>5)||(mezeryZasebou))
						throw "Chyba v mezerách!!";
				}
			}
		}
	} catch (char *chyba) {
		TLabeledEdit *pom=(TLabeledEdit *)Sender;
		MessageDlg(chyba,mtWarning,TMsgDlgButtons() << mbOK,0);
		pom->SetFocus();
	}catch (...) {
		MessageDlg("Nìkde máte chybu, zkontrolujte si své údaje!!",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::lbleEmailExit(TObject *Sender)
{
		try {    //ošetøení emailu,psè,telefonu, apod
		TLabeledEdit *pom=(TLabeledEdit *)Sender;
		pom->Text=pom->Text.Trim();
		String veta = pom->Text;
		int pocet = pom->Text.Length();
    
    if (AnsiContainsText(veta," ")) {
				MessageDlg("Nesmí obsahovat mezery!!",mtWarning,TMsgDlgButtons() << mbOK,0);
				pom->SetFocus();
		}
		if ((pom->Name=="lbleTelCis")||(pom->Name=="lblePSC")||(pom->Name=="lbleCisPop")) {
			for (int i = 1; i <= pocet; i++) {
				if (((veta[i]>='a')&&(veta[i]<='z'))||((veta[i]>='A')&&(veta[i]<='Z'))) {
					throw "Musí obsahovat pouze èísla!!";
				}
			}
		}

	} catch (char *chyba) {
		TLabeledEdit *pom=(TLabeledEdit *)Sender;
		MessageDlg(chyba,mtWarning,TMsgDlgButtons() << mbOK,0);
		pom->SetFocus();
	}catch (...) {
		MessageDlg("Nìkde máte chybu, zkontrolujte si své údaje!!",mtError,TMsgDlgButtons() << mbOK,0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformRegistrace::chboPodminkyClick(TObject *Sender)
{
	if (chboPodminky->Checked==false)
		btnRegistrovat->Enabled=false;
	else  {
		MessageDlg("1. Jsem starší 18 let.\n2. Jsem fyzická osoba ,která je oprávnìna uzavírat sázky dle zákona è. 202/1990 Sb., o loteriích a jiných podobných hrách, v platném znìní.\n3. Souhlasím se zpracováním osobních údajù.\n4. Beru na vìdomí, že tato aplikace se nezakládá na skuteènosti.",mtInformation,TMsgDlgButtons() << mbOK,0);
		btnRegistrovat->Enabled=true;
	}
}
//---------------------------------------------------------------------------


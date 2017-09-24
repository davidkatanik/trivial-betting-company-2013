//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_uzivatel.h"
#include "form_prihlaseni.h"
#include "form_bookmaker.h"
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
TformPrihlaseni *formPrihlaseni;
//---------------------------------------------------------------------------
__fastcall TformPrihlaseni::TformPrihlaseni(TComponent* Owner)
	: TForm(Owner)
{
	if(SeznamZapasu==NULL) {
		String cesta=ExtractFilePath(Application->ExeName)+"Zapasy.dat";
		SeznamZapasu=new TZapasList(cesta);
	}
	if(SeznamUzivatelu==NULL) {
		String cesta=ExtractFilePath(Application->ExeName)+"Uzivatele.dat";
		SeznamUzivatelu=new TUzivatelList(cesta);
	}
	if(SeznamBmakeru==NULL) {
		String cesta=ExtractFilePath(Application->ExeName)+"Bookmakeri.dat";
		SeznamBmakeru=new TBmakerList(cesta);
	}
	if(SeznamTipu==NULL) {
		String cesta=ExtractFilePath(Application->ExeName)+"Tipy.dat";
		SeznamTipu=new TTipList(cesta);
	}
	if(SeznamTiketu==NULL) {
		String cesta=ExtractFilePath(Application->ExeName)+"Tikety.dat";
		SeznamTiketu=new TTiketList(cesta);
	}
}    //vytvorim, alkouji a nactu ze souboru vsechny seznamy
//---------------------------------------------------------------------------
void __fastcall TformPrihlaseni::FormClose(TObject *Sender,TCloseAction &Action)
{
	delete SeznamTipu;
	delete SeznamTiketu;
	delete SeznamZapasu;
	delete SeznamUzivatelu;
	delete SeznamBmakeru;   //ulozeni, smazani a odalokovani vsech seznamu
}      
//---------------------------------------------------------------------------
void __fastcall TformPrihlaseni::btnRegistrovatClick(TObject *Sender)
{
	formRegistrace->ShowModal(); 
}
//---------------------------------------------------------------------------
void __fastcall TformPrihlaseni::btnPrihlasitClick(TObject *Sender)
{
	for (int i = 0; i < SeznamUzivatelu->GetSeznam()->Count; i++) {
			TUzivatel *uziv=(TUzivatel *)(SeznamUzivatelu->GetSeznam()->Items[i]);
			if ((lblePriJmeno->Text.Trim()==uziv->Email)&&(lbleHeslo->Text.Trim()==uziv->Heslo)) {
				formUzivatel->IdUzivatele=(uziv->Id);
				formUzivatel->Show();
				return;
			}
	}
	for (int i = 0; i < SeznamBmakeru->GetSeznam()->Count; i++) {
			TBmaker *bmk=(TBmaker *)(SeznamBmakeru->GetSeznam()->Items[i]);
			if ((lblePriJmeno->Text.Trim()==bmk->Email)&&(lbleHeslo->Text.Trim()==bmk->Heslo)) {
        formBookmaker->Show();
				return;
			}
	}          //projdu seznamy uzivatelu a bmakeru, kde hledam stejny email a heslo abych se prihlasil
	MessageDlg("Uživatel neexistuje, nebo jsou špatnì napsané údaje!",mtInformation,TMsgDlgButtons() << mbOK,0);
}
//---------------------------------------------------------------------------




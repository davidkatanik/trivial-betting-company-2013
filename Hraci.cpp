#include "Hraci.h"
//---------------------------------------------------------------------------
TUzivatelList *SeznamUzivatelu;    // pointer na seznam uzivatelu aplikace
//---------------------------------------------------------------------------
__fastcall TUzivatel::TUzivatel(unsigned Id,String Jmeno,String Prijmeni,String Heslo,
                                String Email,int DenNar,int MesNar,int RokNar,String Mesto,
                                String Adresa,int CisPop,String PSC ,String TelCis,float Konto) :
                      TLog(Id,Jmeno,Prijmeni,Heslo,Email,DenNar,MesNar,
                           RokNar,Mesto,Adresa,CisPop,PSC,TelCis)
{
	this->Konto=Konto;
}
//---------------------------------------------------------------------------
__fastcall TUzivatel::TUzivatel() : TLog()
{
  Konto=0;
}
//---------------------------------------------------------------------------
__fastcall TUzivatelList::TUzivatelList(String Cesta)   // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
{
  this->Cesta=Cesta;
  Seznam=new TList;

  CteniZeSouboru(Cesta,Seznam,&PosledniKlic);
}
//---------------------------------------------------------------------------
__fastcall TUzivatelList::~TUzivatelList()              // zapisu do souboru a odalokuji TList
{
  ZapisDoSouboru(Cesta,Seznam);

  for(int i=0;i<Seznam->Count;i++) {                    // odalokuji seznam
    TUzivatel *uziv=(TUzivatel *)(Seznam->Items[i]);
    delete uziv;
  }
  delete Seznam;
  Seznam=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TUzivatelList::ZapisDoSouboru(String Cesta,TList *Seznam)
{
  if(FileExists(Cesta))
    DeleteFile(Cesta); // vymazu stary soubor a zalozim novy

  TFileStream *str=new TFileStream(Cesta,fmCreate);
  for(int i=0;i<Seznam->Count;i++) {
    TUzivatel *uziv=(TUzivatel *)(Seznam->Items[i]);
    str->Write(uziv,sizeof(TUzivatel));
		//  delete uziv;   // polozku odalokovavame az pri odalokovavani seznamu
  }
  delete str;
}
//---------------------------------------------------------------------------
void __fastcall TUzivatelList::CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic)
{
  if(FileExists(Cesta)) {
    TFileStream *str=new TFileStream(Cesta,fmOpenRead,fmShareDenyNone);
    if(str->Size>0) {
      int delka;
      do {
        TUzivatel *uziv=new TUzivatel();
        delka=str->Read(uziv,sizeof(TUzivatel));
        if(delka==sizeof(TUzivatel)) {
		  		Seznam->Add(uziv);
          *PosledniKlic=uziv->Id;
        }
        else
          delete uziv;
      } while(delka==sizeof(TUzivatel));
    }
    delete str;
  }
}
//---------------------------------------------------------------------------
unsigned __fastcall TUzivatelList::Pridani(TUzivatel &Uzivatel)   // pridani zapasu na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
{
  TUzivatel *uziv=new TUzivatel();
  *uziv=Uzivatel;           // prekopiruji vsechna data, TUzivatel nema v sobe nic dynamicky alokovaneho, takze muzu proste priradit
  PosledniKlic++;
  uziv->Id=PosledniKlic;
  Seznam->Add(uziv);
  return uziv->Id;
}
//---------------------------------------------------------------------------
void _fastcall TUzivatelList::Zruseni(unsigned Klic)              // zruseni polozky s indexem Index ze seznamu
{
  for(int i=0;i<Seznam->Count;i++) {
	TUzivatel *uziv=(TUzivatel *)(Seznam->Items[i]);
	if(uziv->Id==Klic) {
	  delete uziv;                 // odalokuji uzivatele
      Seznam->Delete(i);           // smazu polozku uprostred seznamu
      break;                       // za predpokladu, ze Id je jedinecne, tak koncim
    }
  }
}
//---------------------------------------------------------------------------
TUzivatel *__fastcall TUzivatelList::Najdi(unsigned Klic)         // pohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
{
  for(int i=0;i<Seznam->Count;i++) {
	TUzivatel *uziv=(TUzivatel *)(Seznam->Items[i]);
	if(uziv->Id==Klic) {
	  return uziv;
	}
  }
  return NULL;        // uzivatele s takovym Id jsem nenasel
}
//---------------------------------------------------------------------------


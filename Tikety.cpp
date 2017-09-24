#include "Tikety.h"
//---------------------------------------------------------------------------
TTiketList *SeznamTiketu;    // pointer na seznam tiketu aplikace
//---------------------------------------------------------------------------
__fastcall TTiket :: TTiket(unsigned IdTik,unsigned IdUziv,float KurzTik,float VkladTik,float VyhraTik,
						TDateTime DatTik,bool Vyplaceno)
{
	this->IdTik=IdTik;
	this->IdUziv=IdUziv;
	this->KurzTik=KurzTik;
	this->VkladTik=VkladTik;
	this->VyhraTik=VyhraTik;
	this->DatTik=DatTik;
	this->Vyplaceno=Vyplaceno;
}
//---------------------------------------------------------------------------
__fastcall TTiket :: TTiket()
{
	IdTik=-1;
	IdUziv=0;
	KurzTik=1;
	VkladTik=0;
	VyhraTik=0;
	DatTik=Date();
	Vyplaceno=false;
}
//---------------------------------------------------------------------------
__fastcall TTiketList::TTiketList(String Cesta)   // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
{
  this->Cesta=Cesta;
  Seznam=new TList;

  PosledniKlic=0;
  CteniZeSouboru(Cesta,Seznam,&PosledniKlic);
}
//---------------------------------------------------------------------------
__fastcall TTiketList::~TTiketList()              // zapisu do souboru a odalokuji TList
{
  ZapisDoSouboru(Cesta,Seznam);

  for(int i=0;i<Seznam->Count;i++) {                    // odalokuji seznam
    TTiket *tik=(TTiket *)(Seznam->Items[i]);
    delete tik;
  }
  delete Seznam;
  Seznam=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TTiketList::ZapisDoSouboru(String Cesta,TList *Seznam)
{
  if(FileExists(Cesta))
    DeleteFile(Cesta);                    // vymazu stary soubor a zalozim novy

  TFileStream *str=new TFileStream(Cesta,fmCreate);
  for(int i=0;i<Seznam->Count;i++) {
    TTiket *tik=(TTiket *)(Seznam->Items[i]);
	  str->Write(tik,sizeof(TTiket));
    // delete tik;      // polozku odalokovavame az pri odalokovavani seznamu !!!!!!!!
  }
  delete str;
}
//---------------------------------------------------------------------------
void __fastcall TTiketList::CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic)
{
  if(FileExists(Cesta)) {
    TFileStream *str=new TFileStream(Cesta,fmOpenRead,fmShareDenyNone);
    if(str->Size>0) {
      int delka;
      do {
        TTiket *tik=new TTiket();
        delka=str->Read(tik,sizeof(TTiket));
        if(delka==sizeof(TTiket)) {
		  Seznam->Add(tik);
		  int id=tik->IdTik;
		  *PosledniKlic=id;
        }
        else
          delete tik;
	  } while(delka==sizeof(TTiket));
    }
    delete str;
  }
}
//---------------------------------------------------------------------------
unsigned __fastcall TTiketList::Pridani(TTiket &Tiket)   // pridani zapasu na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
{
  TTiket *tik=new TTiket();
  *tik=Tiket;           // prekopiruji vsechna data, TUzivatel nema v sobe nic dynamicky alokovaneho, takze muzu proste priradit
  PosledniKlic++;
  tik->IdTik=PosledniKlic;
  Seznam->Add(tik);
  return tik->IdTik;
}
//---------------------------------------------------------------------------
void _fastcall TTiketList::Zruseni(unsigned Klic)              // zruseni polozky s indexem Index ze seznamu
{
  for(int i=0;i<Seznam->Count;i++) {
	TTiket *tik=(TTiket *)(Seznam->Items[i]);
	if(tik->IdTik==Klic) {
	  delete tik;                 // odalokuji tiket
      Seznam->Delete(i);           // smazu polozku uprostred seznamu
      break;                       // za predpokladu, ze Id je jedinecne, tak koncim
    }
  }
}
//---------------------------------------------------------------------------
TTiket *__fastcall TTiketList::Najdi(unsigned Klic)         // pohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
{
  for(int i=0;i<Seznam->Count;i++) {
	TTiket *tik=(TTiket *)(Seznam->Items[i]);
	if(tik->IdTik==Klic) {
	  return tik;
	}
  }
  return NULL;        // tiket s takovym Id jsem nenasel
}
//---------------------------------------------------------------------------

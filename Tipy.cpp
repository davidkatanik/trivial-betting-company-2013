#include "Tipy.h"
//---------------------------------------------------------------------------
TTipList *SeznamTipu;    // pointer na seznam tipu uzivatele na zapasy
//---------------------------------------------------------------------------
TTip :: TTip(unsigned IdTipu,unsigned IdZap,unsigned IdTik,int Tip,bool Vyhra) {
	this->IdTipu=IdTipu;
	this->IdZap=IdZap;
	this->IdTik=IdTik;
	this->Tip=Tip;
	this->Vyhra=Vyhra;
}
//---------------------------------------------------------------------------
TTip :: TTip(){
	IdTipu=0;
	IdZap=0;
	IdTik=0;
	Tip=-1;
	Vyhra=false;
}
//---------------------------------------------------------------------------
__fastcall TTipList::TTipList(String Cesta)   // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
{
  this->Cesta=Cesta;
  Seznam=new TList;

  PosledniKlic=0;
  CteniZeSouboru(Cesta,Seznam,&PosledniKlic);
}
//---------------------------------------------------------------------------
__fastcall TTipList::~TTipList()              // zapisu do souboru a odalokuji TList
{
  ZapisDoSouboru(Cesta,Seznam);

  for(int i=0;i<Seznam->Count;i++) {                    // odalokuji seznam
    TTip *tip=(TTip *)(Seznam->Items[i]);
    delete tip;
  }
  delete Seznam;
  Seznam=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TTipList::ZapisDoSouboru(String Cesta,TList *Seznam)
{
  if(FileExists(Cesta))
    DeleteFile(Cesta);                    // vymazu stary soubor a zalozim novy

  TFileStream *str=new TFileStream(Cesta,fmCreate);
  for(int i=0;i<Seznam->Count;i++) {
    TTip *tip=(TTip *)(Seznam->Items[i]);
    str->Write(tip,sizeof(TTip));
    // delete tip;         // polozku odalokovavame az pri odalokovavani seznamu !!!!!!!!
  }
  delete str;
}
//---------------------------------------------------------------------------
void __fastcall TTipList::CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic)
{
  if(FileExists(Cesta)) {
    TFileStream *str=new TFileStream(Cesta,fmOpenRead,fmShareDenyNone);
    if(str->Size>0) {
      int delka;
      do {
        TTip *tip=new TTip();
        delka=str->Read(tip,sizeof(TTip));
        if(delka==sizeof(TTip)) {
					Seznam->Add(tip);
					*PosledniKlic=tip->IdTipu;
				}
				else
					delete tip;
      } while(delka==sizeof(TTip));
    }
    delete str;
  }
}
//---------------------------------------------------------------------------
unsigned __fastcall TTipList::Pridani(TTip &Tip)   // pridani tipu na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
{
  TTip *tip=new TTip();
	*tip=Tip;           // prekopiruji vsechna data, TTip nema v sobe nic dynamicky alokovaneho, takze muzu proste priradit
  PosledniKlic++;
  tip->IdTipu=PosledniKlic;
  Seznam->Add(tip);
  return tip->IdTipu;
}
//---------------------------------------------------------------------------
void _fastcall TTipList::Zruseni(unsigned Klic)              // zruseni polozky s indexem Index ze seznamu
{
  for(int i=0;i<Seznam->Count;i++) {
	TTip *tip=(TTip *)(Seznam->Items[i]);
	if(tip->IdTipu==Klic) {
	  delete tip;                 // odalokuji tip
      Seznam->Delete(i);           // smazu polozku uprostred seznamu
      break;                       // za predpokladu, ze Id je jedinecne, tak koncim
    }
  }
}
//---------------------------------------------------------------------------
TTip *__fastcall TTipList::Najdi(unsigned Klic)         // pohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
{
  for(int i=0;i<Seznam->Count;i++) {
	TTip *tip=(TTip *)(Seznam->Items[i]);
	if(tip->IdTipu==Klic) {
	  return tip;
	}
  }
  return NULL;        // tip s takovym Id jsem nenasel
}
//---------------------------------------------------------------------------
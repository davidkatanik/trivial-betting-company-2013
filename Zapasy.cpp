#include "Zapasy.h"
//---------------------------------------------------------------------------
TZapasList *SeznamZapasu;    // pointer na seznam zapasu aplikace
//---------------------------------------------------------------------------
__fastcall TZapas :: TZapas(unsigned IdZap, String JmenoD, String JmenoH, int SkoreD,
							int SkoreH, float KurzD,float KurzRem,float KurzH,TDateTime DatZap,
							TDateTime CasZap,bool Dohrano)
{
	this->IdZap=IdZap;
	strncpy(this->JmenoD,JmenoD.c_str(),sizeof(this->JmenoD)-1);
	this->JmenoD[sizeof(this->JmenoD)-1]=0;
	strncpy(this->JmenoH,JmenoH.c_str(),sizeof(this->JmenoH)-1);
	this->JmenoH[sizeof(this->JmenoH)-1]=0;
	this->SkoreD=SkoreD;
	this->SkoreH=SkoreH;
	this->KurzD=KurzD;
	this->KurzRem=KurzRem;
	this->KurzH=KurzH;
	this->DatZap=DatZap;
	this->CasZap=CasZap;
	this->Dohrano=Dohrano;
}
//---------------------------------------------------------------------------
__fastcall TZapas :: TZapas()
{
	IdZap=0;
	strcpy(JmenoD,"_Domaci") ;
	strcpy(JmenoH,"_Hoste");
	SkoreD=NULL;
	SkoreH= NULL;
	KurzD= NULL;
	KurzRem= NULL;
	KurzH= NULL;
	DatZap= NULL;
	CasZap= NULL;
	Dohrano=false;
}
//---------------------------------------------------------------------------
void __fastcall TZapas :: UpravZapas(String JmenoD, String JmenoH, int SkoreD, int SkoreH, float KurzD,float KurzRem,float KurzH,TDateTime DatZap,TDateTime CasZap,bool Dohrano)
{
	strncpy(this->JmenoD,JmenoD.c_str(),sizeof(this->JmenoD)-1);
	this->JmenoD[sizeof(this->JmenoD)-1]=0;
	strncpy(this->JmenoH,JmenoH.c_str(),sizeof(this->JmenoH)-1);
	this->JmenoH[sizeof(this->JmenoH)-1]=0;
	this->SkoreD=SkoreD;
	this->SkoreH=SkoreH;
	this->KurzD=KurzD;
	this->KurzRem=KurzRem;
	this->KurzH=KurzH;
	this->DatZap=DatZap;
	this->CasZap=CasZap;
	this->Dohrano=Dohrano;
}
//---------------------------------------------------------------------------
__fastcall TZapasList::TZapasList(String Cesta)   // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
{
  this->Cesta=Cesta;
  Seznam=new TList;
  PosledniKlic=0;

  CteniZeSouboru(Cesta,Seznam,&PosledniKlic);
}
//---------------------------------------------------------------------------
__fastcall TZapasList::~TZapasList()              // zapisu do souboru a odalokuji TList
{
  ZapisDoSouboru(Cesta,Seznam);

  for(int i=0;i<Seznam->Count;i++) {                    // odalokuji seznam
	  TZapas *zap=(TZapas *)(Seznam->Items[i]);
    delete zap;
  }
  delete Seznam;
  Seznam=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TZapasList::ZapisDoSouboru(String Cesta,TList *Seznam)
{
  if(FileExists(Cesta))
    DeleteFile(Cesta);                    // vymazu stary soubor a zalozim novy

  TFileStream *str=new TFileStream(Cesta,fmCreate);
  for(int i=0;i<Seznam->Count;i++) {
    TZapas *zap=(TZapas *)(Seznam->Items[i]);
    str->Write(zap,sizeof(TZapas));
    // delete zap;      // polozku odalokovavame az pri odalokovavani seznamu !!!!!!!!
  }
  delete str;
}
//---------------------------------------------------------------------------
void __fastcall TZapasList::CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic)
{
  if(FileExists(Cesta)) {
    TFileStream *str=new TFileStream(Cesta,fmOpenRead,fmShareDenyNone);
    if(str->Size>0) {
      int delka;
      do {
		TZapas *zap=new TZapas();
		delka=str->Read(zap,sizeof(TZapas));
		if(delka==sizeof(TZapas)) {
		  Seznam->Add(zap);
		  int id=zap->IdZap;
		  *PosledniKlic=id;
		}
        else
          delete zap;
	  } while(delka==sizeof(TZapas));
    }
    delete str;
  }
}
//---------------------------------------------------------------------------
unsigned __fastcall TZapasList::Pridani(TZapas &Zapas)   // pridani zapasu na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
{
  TZapas *zap=new TZapas();
  *zap=Zapas;           // prekopiruji vsechna data, TZapas nema v sobe nic dynamicky alokovaneho, takze muzu proste priradit
  PosledniKlic++;
  zap->IdZap=PosledniKlic;
  Seznam->Add(zap);
  return zap->IdZap;
}
//---------------------------------------------------------------------------
void _fastcall TZapasList::Zruseni(unsigned Klic)              // zruseni polozky s indexem Index ze seznamu
{
  for(int i=0;i<Seznam->Count;i++) {
	TZapas *zap=(TZapas *)(Seznam->Items[i]);
	if(zap->IdZap==Klic) {
	  delete zap;                 // odalokuji zapas
      Seznam->Delete(i);           // smazu polozku uprostred seznamu
      break;                       // za predpokladu, ze Id je jedinecne, tak koncim
    }
  }
}
//---------------------------------------------------------------------------
TZapas *__fastcall TZapasList::Najdi(unsigned Klic)         // pohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
{
  for(int i=0;i<Seznam->Count;i++) {
	TZapas *zap=(TZapas *)(Seznam->Items[i]);
	if(zap->IdZap==Klic) {
	  return zap;
	}
  }
  return NULL;        // zapas s takovym Id jsem nenasel
}
//---------------------------------------------------------------------------

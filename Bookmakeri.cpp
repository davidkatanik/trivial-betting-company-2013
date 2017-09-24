#include "Bookmakeri.h"
//---------------------------------------------------------------------------
TBmakerList *SeznamBmakeru;    // pointer na seznam bookmakeru aplikace
//---------------------------------------------------------------------------
__fastcall TBmaker::TBmaker(unsigned Id,String Jmeno,String Prijmeni,String Heslo,
                                String Email,int DenNar,int MesNar,int RokNar,String Mesto,
								String Adresa,int CisPop,String PSC ,String TelCis) :
					TLog(Id,Jmeno,Prijmeni,Heslo,Email,DenNar,MesNar,
						   RokNar,Mesto,Adresa,CisPop,PSC,TelCis)
{
}
//---------------------------------------------------------------------------
__fastcall TBmaker::TBmaker() : TLog()
{
}
//---------------------------------------------------------------------------
__fastcall TBmakerList::TBmakerList(String Cesta)   // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
{
  this->Cesta=Cesta;
  Seznam=new TList;

  CteniZeSouboru(Cesta,Seznam,&PosledniKlic);
}
//---------------------------------------------------------------------------
__fastcall TBmakerList::~TBmakerList()              // zapisu do souboru a odalokuji TList
{
  ZapisDoSouboru(Cesta,Seznam);

  for(int i=0;i<Seznam->Count;i++) {                    // odalokuji seznam
	  TBmaker *bmk=(TBmaker *)(Seznam->Items[i]);
    delete bmk;
  }
  delete Seznam;
  Seznam=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TBmakerList::ZapisDoSouboru(String Cesta,TList *Seznam)
{
  if(FileExists(Cesta))
    DeleteFile(Cesta);                    // vymazu stary soubor a zalozim novy

  TFileStream *str=new TFileStream(Cesta,fmCreate);
  for(int i=0;i<Seznam->Count;i++) {
    TBmaker *bmk=(TBmaker *)(Seznam->Items[i]);
    str->Write(bmk,sizeof(TBmaker));
    // delete bmk;          // polozku odalokovavame az pri odalokovavani seznamu !!!!!!!!
                            // jinak bychom v destruktoru odalokovavali uz odalokovane
  }
  delete str;
}
//---------------------------------------------------------------------------
void __fastcall TBmakerList::CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic)
{
  if(FileExists(Cesta)) {
    TFileStream *str=new TFileStream(Cesta,fmOpenRead,fmShareDenyNone);
    if(str->Size>0) {
      int delka;
      do {
        TBmaker *bmk=new TBmaker();
        delka=str->Read(bmk,sizeof(TBmaker));
        if(delka==sizeof(TBmaker)) {
          Seznam->Add(bmk);
          *PosledniKlic=bmk->Id;
        }
        else
          delete bmk;
      } while(delka==sizeof(TBmaker));
    }
    delete str;
  }
}
//---------------------------------------------------------------------------
unsigned __fastcall TBmakerList::Pridani(TBmaker &Bmaker)   // pridani zapasu na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
{
  TBmaker *bmk=new TBmaker();
  *bmk=Bmaker;           // prekopiruji vsechna data, TBmaker nema v sobe nic dynamicky alokovaneho, takze muzu proste priradit
  PosledniKlic++;
  bmk->Id=PosledniKlic;
  Seznam->Add(bmk);
  return bmk->Id;
}
//---------------------------------------------------------------------------
void _fastcall TBmakerList::Zruseni(unsigned Klic)              // zruseni polozky s indexem Index ze seznamu
{
  for(int i=0;i<Seznam->Count;i++) {
	TBmaker *bmk=(TBmaker *)(Seznam->Items[i]);
	if(bmk->Id==Klic) {
	  delete bmk;                 // odalokuji bmakera
      Seznam->Delete(i);           // smazu polozku uprostred seznamu
	  break;                       // za predpokladu, ze Id je jedinecne, tak koncim
	}
  }
}
//---------------------------------------------------------------------------
TBmaker *__fastcall TBmakerList::Najdi(unsigned Klic)         // pohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
{
  for(int i=0;i<Seznam->Count;i++) {
	TBmaker *bmk=(TBmaker *)(Seznam->Items[i]);
	if(bmk->Id==Klic) {
	  return bmk;
	}
  }
  return NULL;        // bmaker s takovym Id jsem nenasel
}
//---------------------------------------------------------------------------


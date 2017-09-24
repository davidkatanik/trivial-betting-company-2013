//---------------------------------------------------------------------------

#ifndef BookmakeriH
#define BookmakeriH

#include "ZakladniTridy.h"
//---------------------------------------------------------------------------
class TBmaker : public TLog
{
public :
  __fastcall TBmaker(unsigned Id,String Jmeno,String Prijmeni,String Heslo,
                                String Email,int DenNar,int MesNar,int RokNar,String Mesto,
								String Adresa,int CisPop,String PSC ,String TelCis);
  __fastcall TBmaker(String Jmeno,String Heslo);
  __fastcall TBmaker();
};
class TBmakerList
{
private:
  TList *Seznam;
  String Cesta;                            // cesta, kde je ulozen seznam na HDD
  unsigned PosledniKlic;
  void __fastcall ZapisDoSouboru(String Cesta,TList *Seznam);
  void __fastcall CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic);
public:
  __fastcall TBmakerList(String Cesta);      // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
  __fastcall ~TBmakerList();                 // zapisu do souboru a odalokuji TList
  unsigned __fastcall Pridani(TBmaker &Bmaker);   // pridani hrace na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
  void __fastcall Zruseni(unsigned Klic);             // zruseni polozky s indexem Index ze seznamu
  TBmaker *__fastcall Najdi(unsigned Klic);         // prohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
  TList* __fastcall GetSeznam() {return Seznam;};      // kdybych nekdy potreboval se seznamem pracovat mimo tridu
  unsigned __fastcall DejPosledniKlic() { return PosledniKlic; };

};

extern TBmakerList *SeznamBmakeru;
#endif

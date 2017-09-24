//---------------------------------------------------------------------------
#ifndef HraciH
#define HraciH

#include "ZakladniTridy.h"
//---------------------------------------------------------------------------
class TUzivatel : public TLog
{
public :
	float Konto;
  __fastcall TUzivatel(unsigned Id,String Jmeno,String Prijmeni,
                       String Heslo,String Email,int DenNar,int MesNar,int RokNar,
											 String Mesto,String Adresa,int CisPop,String PSC ,
					   String TelCis,float Konto);
  __fastcall TUzivatel();
};

class TUzivatelList
{
private:
  TList *Seznam;
  String Cesta;                            // cesta, kde je ulozen seznam na HDD
  unsigned PosledniKlic;
  void __fastcall ZapisDoSouboru(String Cesta,TList *Seznam);
  void __fastcall CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic);
public:
  __fastcall TUzivatelList(String Cesta);      // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
  __fastcall ~TUzivatelList();                 // zapisu do souboru a odalokuji TList
	unsigned __fastcall Pridani(TUzivatel &Uzivatel);   // pridani hrace na konec seznamu pomoci Add a vracelo
																											//by to cislo prideleneho klice, treba se to bude hodit
  void __fastcall Zruseni(unsigned Klic);             // zruseni polozky s indexem Index ze seznamu
  TUzivatel *__fastcall Najdi(unsigned Klic);         // prohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
  TList* __fastcall GetSeznam() {return Seznam;}      // kdybych nekdy potreboval se seznamem pracovat mimo tridu
  unsigned __fastcall DejPosledniKlic() { return PosledniKlic; }
};

extern TUzivatelList *SeznamUzivatelu;

#endif

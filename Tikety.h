//---------------------------------------------------------------------------

#ifndef TiketyH
#define TiketyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TTiket
{
public :
	unsigned IdTik;
	unsigned IdUziv;
	float KurzTik;
	float VkladTik;
	float VyhraTik;
	TDateTime DatTik;
	bool Vyplaceno;
	__fastcall TTiket(unsigned IdTik,unsigned IdUziv,float KurzTik,	float VkladTik,float VyhraTik,
						TDateTime DatTik,bool Vyplaceno);
	__fastcall TTiket();
};

class TTiketList
{
private:
  TList *Seznam;
  String Cesta;                            // cesta, kde je ulozen seznam na HDD
  unsigned PosledniKlic;
  void __fastcall ZapisDoSouboru(String Cesta,TList *Seznam);
  void __fastcall CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic);
public:
  __fastcall TTiketList(String Cesta);      // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
  __fastcall ~TTiketList();                 // zapisu do souboru a odalokuji TList
  unsigned __fastcall Pridani(TTiket &Tiket);   // pridani hrace na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
  void __fastcall Zruseni(unsigned Klic);             // zruseni polozky s indexem Index ze seznamu
  TTiket *__fastcall Najdi(unsigned Klic);         // prohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
  TList* __fastcall GetSeznam() {return Seznam;}      // kdybych nekdy potreboval se seznamem pracovat mimo tridu
  unsigned __fastcall DejPosledniKlic() { return PosledniKlic; }
};

extern TTiketList *SeznamTiketu;

#endif


//---------------------------------------------------------------------------

#ifndef TipyH
#define TipyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TTip {
	public :
		unsigned IdTipu;
		unsigned IdZap;
		unsigned IdTik;
		int Tip;
		bool Vyhra;
	TTip(unsigned IdTipu,unsigned IdZap,unsigned IdTik,int Tip,bool Vyhra);
	TTip();

};

class TTipList
{
	private:
		TList *Seznam;
		String Cesta;                            // cesta, kde je ulozen seznam na HDD
		unsigned PosledniKlic;
		void __fastcall ZapisDoSouboru(String Cesta,TList *Seznam);
		void __fastcall CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic);
	public:
		__fastcall TTipList(String Cesta);      // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
		__fastcall ~TTipList();                 // zapisu do souboru a odalokuji TList
		unsigned __fastcall Pridani(TTip &Tip);   // pridani hrace na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
		void __fastcall Zruseni(unsigned Klic);             // zruseni polozky s indexem Index ze seznamu
		TTip *__fastcall Najdi(unsigned Klic);         // prohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
		TList* __fastcall GetSeznam() {return Seznam;}      // kdybych nekdy potreboval se seznamem pracovat mimo tridu
		unsigned __fastcall DejPosledniKlic() { return PosledniKlic; }
};

extern TTipList *SeznamTipu;
#endif

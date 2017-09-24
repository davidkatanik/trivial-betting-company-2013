//---------------------------------------------------------------------------

#ifndef ZapasyH
#define ZapasyH
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TZapas
{
public :
	unsigned IdZap;
	char JmenoD[50];
	char JmenoH[50];
	int SkoreD;
	int SkoreH;
	float KurzD;
	float KurzRem;
	float KurzH;
	TDateTime DatZap;
	TDateTime CasZap;
	bool Dohrano;

	__fastcall TZapas(unsigned IdZap, String JmenoD, String JmenoH, int SkoreD, int SkoreH,
	float KurzD,float KurzRem,float KurzH,TDateTime DatZap,TDateTime CasZap,bool Dohrano);
	__fastcall TZapas();

	void __fastcall UpravZapas(String JmenoD, String JmenoH, int SkoreD, int SkoreH, float KurzD,float KurzRem,float KurzH,TDateTime DatZap,TDateTime CasZap,bool Dohrano);
};

class TZapasList
{
private:
  TList *Seznam;
  String Cesta;                            // cesta, kde je ulozen seznam na HDD
  unsigned PosledniKlic;
  void __fastcall ZapisDoSouboru(String Cesta,TList *Seznam);
  void __fastcall CteniZeSouboru(String Cesta,TList *Seznam,unsigned *PosledniKlic);
public:
  __fastcall TZapasList(String Cesta);      // zalozim TList a zapamatuji si cestu na HDD a seznam i nactu
  __fastcall ~TZapasList();                 // zapisu do souboru a odalokuji TList
  unsigned __fastcall Pridani(TZapas &Zapas);   // pridani hrace na konec seznamu pomoci Add a vracelo by to cislo prideleneho klice, treba se to bude hodit
  void __fastcall Zruseni(unsigned Klic);             // zruseni polozky s indexem Index ze seznamu
  TZapas *__fastcall Najdi(unsigned Klic);         // prohleda v seznamu a vrati adresu nalezene polozky, jinak vrati NULL
  TList* __fastcall GetSeznam() {return Seznam;}      // kdybych nekdy potreboval se seznamem pracovat mimo tridu
  unsigned __fastcall DejPosledniKlic() { return PosledniKlic; }
};

extern TZapasList *SeznamZapasu;

#endif

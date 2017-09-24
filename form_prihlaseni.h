//---------------------------------------------------------------------------

#ifndef form_prihlaseniH
#define form_prihlaseniH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TformPrihlaseni : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblUvitaci;
	TLabeledEdit *lblePriJmeno;
	TLabeledEdit *lbleHeslo;
	TButton *btnPrihlasit;
	TStaticText *sttPrava;
	TButton *btnRegistrovat;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnRegistrovatClick(TObject *Sender);
	void __fastcall btnPrihlasitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformPrihlaseni(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformPrihlaseni *formPrihlaseni;
//---------------------------------------------------------------------------
#endif

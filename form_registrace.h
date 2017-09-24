//---------------------------------------------------------------------------

#ifndef form_registraceH
#define form_registraceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformRegistrace : public TForm
{
__published:	// IDE-managed Components
	TStaticText *sttPrava;
	TLabeledEdit *lbleJmeno;
	TLabeledEdit *lblePrijmeni;
	TLabeledEdit *lbleEmail;
	TLabeledEdit *lbleTelCis;
	TLabeledEdit *lbleMesto;
	TLabeledEdit *lbleAdresa;
	TLabeledEdit *lbleCisPop;
	TLabeledEdit *lblePSC;
	TCheckBox *chboPodminky;
	TButton *btnRegistrovat;
	TComboBox *cboDenNar;
	TComboBox *cboMesNar;
	TComboBox *cboRokNar;
	TLabeledEdit *lbleHeslo1;
	TLabeledEdit *lbleHeslo2;
	TStaticText *sttRegistrace;
	TStaticText *sttDen;
	TStaticText *sttMesic;
	TStaticText *sttRok;
	TButton *btnZrusitReg;
	TStaticText *sttUdaje;
	void __fastcall btnRegistrovatClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cboMesNarChange(TObject *Sender);
	void __fastcall lbleJmenoExit(TObject *Sender);
	void __fastcall lbleEmailExit(TObject *Sender);
	void __fastcall chboPodminkyClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformRegistrace(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRegistrace *formRegistrace;
//---------------------------------------------------------------------------
#endif

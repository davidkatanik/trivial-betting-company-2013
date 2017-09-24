//---------------------------------------------------------------------------

#ifndef form_bookmakerH
#define form_bookmakerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformBookmaker : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pcBookmaker;
	TTabSheet *tsZapasy;
	TTabSheet *tsUzivatele;
	TTabSheet *tsBookmakeri;
	TButton *btnPridatBmk;
	TListBox *libBmakeri;
	TButton *btnNajdiBmk;
	TEdit *eVybranyBmk;
	TButton *btnOdebratBmk;
	TButton *btnUpravBmk;
	TLabeledEdit *lbleIdBmk;
	TButton *btnPridatUziv;
	TListBox *libUzivatele;
	TButton *btnNajdiUziv;
	TEdit *eVybranyUziv;
	TButton *btnOdebratUziv;
	TButton *btnUpravUziv;
	TLabeledEdit *lbleIdUziv;
	TListBox *libZapasy;
	TLabeledEdit *lbleJmenoD;
	TLabeledEdit *lbleJmenoH;
	TEdit *eSkoreH;
	TEdit *eSkoreD;
	TStaticText *sttVS;
	TButton *btnPridatZ;
	TLabeledEdit *lbleKurzD;
	TLabeledEdit *lbleKurzRem;
	TLabeledEdit *lbleKurzH;
	TStaticText *sttResult;
	TStaticText *sttKurzy;
	TDateTimePicker *dtpDatum;
	TDateTimePicker *dtpCas;
	TButton *btnOdebratZ;
	TButton *btnZmenZ;
	TCheckBox *cboDohrano;
	TEdit *eVyhledanyZ;
	TEdit *eIdZ;
	TButton *btnNajdiZ;
	TTabSheet *tsTikety;
	TLabel *lblDatTik;
	TListBox *libTikety;
	TStaticText *sttDatumTiketu;
	TEdit *eIdTiketu;
	TGroupBox *gboTiket2;
	TLabel *lblJmenoDTik;
	TLabel *lblJmenoHTik;
	TLabel *lblCasZapTik;
	TLabel *lblDatZapTik;
	TLabel *lblCastkaVyhra;
	TLabel *lblCKurz;
	TLabel *lblVyhodnoceno;
	TLabel *lblVyhraZap;
	TLabel *lblKurzTip;
	TLabel *lblVysTik;
	TListBox *libZapasyTiketu;
	TStaticText *sttVS3;
	TStaticText *sttVybranoTik;
	TStaticText *sttKurz;
	TLabeledEdit *lbleVklad;
	TStaticText *sttPoplatek;
	TLabeledEdit *lbleCastka;
	TStaticText *sttVyhra;
	TStaticText *lblCelkK;
	TStaticText *lblVyhra;
	TStaticText *sttVyhodnoceno;
	TStaticText *sttKC;
	TEdit *eSD;
	TEdit *eSH;
	TButton *btnSmazatTiket;
	TLabeledEdit *lbleStavKonta;
	TLabeledEdit *lbleOdecistPenize;
	TButton *btnOdecistPenize;
	TButton *btnPricistPenize;
	TTabSheet *tsStatistiky;
	TLabeledEdit *lblePocetUzivatelu;
	TLabeledEdit *lblePocetBmakeru;
	TLabeledEdit *lblePocetSpravnychTipu;
	TLabeledEdit *lblePocetZapasu;
	TLabeledEdit *lblePocetDohZapasu;
	TLabeledEdit *lblePocetTipu;
	TLabeledEdit *lblePenizeUzivatelu;
	TLabeledEdit *lbleVydelanePenize;
	TLabeledEdit *lbleProhranePenize;
	TLabeledEdit *lblePocetProTiketu;
	TLabeledEdit *lblePocetVyhTiketu;
	TLabeledEdit *lbleVsazenePenize;
	TLabeledEdit *lblePocetTiketu;
	TLabeledEdit *lblePocetNevyhodnocenych;
	TButton *btnVyhodnotitZnovu;
	TButton *btnNajdiTiket;
	TLabeledEdit *lblePocSpravnychTipu;
	TLabeledEdit *lblePocVyhranychTiketu;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnPridatBmkClick(TObject *Sender);
	void __fastcall btnUpravBmkClick(TObject *Sender);
	void __fastcall btnNajdiBmkClick(TObject *Sender);
	void __fastcall btnOdebratBmkClick(TObject *Sender);
	void __fastcall libBmakeriClick(TObject *Sender);
	void __fastcall btnPridatUzivClick(TObject *Sender);
	void __fastcall btnUpravUzivClick(TObject *Sender);
	void __fastcall btnNajdiUzivClick(TObject *Sender);
	void __fastcall btnOdebratUzivClick(TObject *Sender);
	void __fastcall libUzivateleClick(TObject *Sender);
	void __fastcall btnPridatZClick(TObject *Sender);
	void __fastcall btnOdebratZClick(TObject *Sender);
	void __fastcall btnZmenZClick(TObject *Sender);
	void __fastcall cboDohranoClick(TObject *Sender);
	void __fastcall btnNajdiZClick(TObject *Sender);
	void __fastcall libZapasyClick(TObject *Sender);
	void __fastcall libTiketyClick(TObject *Sender);
	void __fastcall libZapasyTiketuClick(TObject *Sender);
	void __fastcall btnNajdiTiketClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnSmazatTiketClick(TObject *Sender);
	void __fastcall btnOdecistPenizeClick(TObject *Sender);
	void __fastcall btnPricistPenizeClick(TObject *Sender);
	void __fastcall tsStatistikyShow(TObject *Sender);
	void __fastcall btnVyhodnotitZnovuClick(TObject *Sender);
	void __fastcall btnVyhodnotitZnovuEnter(TObject *Sender);
	void __fastcall lbleJmenoDExit(TObject *Sender);
private:	// User declarations
	void __fastcall UkazSeznamBmakeru();
	void __fastcall UkazSeznamUzivatelu();
	void __fastcall UkazSeznamZapasu();
	void __fastcall UkazSeznamTiketu();
	void __fastcall UkazSeznamZapasuTiketu();
	void _fastcall UkazStatistiky(unsigned Id);
	void __fastcall VymazNevyuziteZapasy();

	void __fastcall ZjistiUspesnostTiketu();
	__fastcall ZjistiPocetZapasuTiketu(unsigned IdT);

	void __fastcall VyhodnotZapasy();

	unsigned IdTiketu;

public:		// User declarations
	__fastcall TformBookmaker(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformBookmaker *formBookmaker;
//---------------------------------------------------------------------------
#endif

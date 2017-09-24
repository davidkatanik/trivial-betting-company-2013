//---------------------------------------------------------------------------

#ifndef form_uzivatelH
#define form_uzivatelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TformUzivatel : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pcUzivatel;
	TTabSheet *tsSazky;
	TTabSheet *tsTikety;
	TListBox *libZapasy;
	TGroupBox *gboZapas;
	TLabel *lblJmenoD;
	TLabel *lblJmenoH;
	TLabel *lblDatZap;
	TLabel *lblCasZap;
	TStaticText *sttVS1;
	TStaticText *stt1;
	TStaticText *stt0;
	TStaticText *stt2;
	TButton *btnPridatD;
	TButton *btnPridatR;
	TButton *btnPridatH;
	TStaticText *sttPrava;
	TGroupBox *gboTiket2;
	TLabel *lblJmenoDTik2;
	TLabel *lblJmenoHTik2;
	TLabel *lblCasZapTik2;
	TLabel *lblDatZapTik2;
	TLabel *lblCastkaVyhra2;
	TLabel *lblCKurz2;
	TLabel *lblVyhodnoceno;
	TListBox *libZapasyTiketu;
	TStaticText *sttVS3;
	TStaticText *sttVybranoTik2;
	TStaticText *sttKurzTipu;
	TLabeledEdit *lbleVklad2;
	TStaticText *sttPoplatek2;
	TLabeledEdit *lbleCastka2;
	TStaticText *sttVyhra;
	TStaticText *lblCelkK2;
	TStaticText *lblVyhra2;
	TStaticText *sttVyhodnoceno;
	TStaticText *sttKC;
	TListBox *libTikety;
	TStaticText *sttDatumTiketu;
	TLabel *lblDatTik;
	TButton *btnNajdiTiket;
	TEdit *eIdTiketu;
	TLabel *lblVyhraZap;
	TGroupBox *gboTiket;
	TLabel *lblJmenoDTik;
	TLabel *lblJmenoHTik;
	TLabel *lblCasZapTik;
	TLabel *lblDatZapTik;
	TLabel *lblVysTik;
	TLabel *lblKurzTik;
	TLabel *lblVyhra;
	TLabel *lblCastkaVyhra;
	TLabel *lblKC;
	TLabel *lblCelkK;
	TLabel *lblCKurz;
	TListBox *libTiket;
	TStaticText *sttVS2;
	TStaticText *sttVybranoTik;
	TStaticText *sttKurz;
	TLabeledEdit *lbleVklad;
	TButton *btnPrepocitat;
	TStaticText *sttPoplatek;
	TBitBtn *bbtnOdebratZTik;
	TBitBtn *bbtnVsadit;
	TLabeledEdit *lbleCastka;
	TTabSheet *tsKonto;
	TLabeledEdit *lbleZustatek;
	TTabSheet *tsZadaniPrace;
	TMemo *mZadani;
	TLabel *lblKurzTik2;
	TLabel *lblVysTik2;
	TEdit *eSkoreD;
	TEdit *eSkoreH;
	TLabeledEdit *lblePridatPenize;
	TButton *btnPridatPenize;
	TLabeledEdit *lbleVybratPenize;
	TButton *btnVybratPenize;
	TLabeledEdit *lblePocSpravnychTipu;
	TLabeledEdit *lblePocVyhranychTiketu;
	TTabSheet *tsProfil;
	TLabeledEdit *lbleMesto;
	TLabeledEdit *lbleUlice;
	TLabeledEdit *lbleCisPop;
	TLabeledEdit *lblePSC;
	TLabeledEdit *lbleTelCis;
	TButton *btnZmenUdaje;
	TLabeledEdit *lbleStareHeslo;
	TLabeledEdit *lbleHeslo1;
	TLabeledEdit *lbleHeslo2;
	TButton *btnZmenHeslo;
	void __fastcall libZapasyClick(TObject *Sender);
	void __fastcall btnPridatDClick(TObject *Sender);
	void __fastcall libTiketClick(TObject *Sender);
	void __fastcall bbtnOdebratZTikClick(TObject *Sender);
	void __fastcall bbtnVsaditClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnPrepocitatClick(TObject *Sender);
	void __fastcall libTiketyClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall libZapasyTiketuClick(TObject *Sender);
	void __fastcall tsKontoShow(TObject *Sender);
	void __fastcall btnPridatPenizeClick(TObject *Sender);
	void __fastcall btnVybratPenizeClick(TObject *Sender);
	void __fastcall btnNajdiTiketClick(TObject *Sender);
	void __fastcall tsProfilShow(TObject *Sender);
	void __fastcall btnZmenUdajeClick(TObject *Sender);
	void __fastcall btnZmenHesloClick(TObject *Sender);
private:	// User declarations
	float CelkovyKurzT;
	unsigned PosledniIdTiketu;
	unsigned IdTiketu;

	void __fastcall UkazSeznamTipu();
	void __fastcall UkazSeznamZapasu();
	void __fastcall UkazSeznamTiketuUzivatele();
	void __fastcall UkazSeznamZapasuTiketu();
	void __fastcall UkazStatistiky();
public:		// User declarations
  unsigned IdUzivatele;
	void __fastcall UkazCelkovyKurz();
	__fastcall TformUzivatel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformUzivatel *formUzivatel;
//---------------------------------------------------------------------------
#endif

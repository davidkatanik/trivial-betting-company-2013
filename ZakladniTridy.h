#ifndef ZakladniTridyH
#define ZakladniTridyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------

class TLog
{
	public: // datove cleny nechame public, nikdo jiny s nima pracovat nebude
		unsigned Id;          //Id
		char Jmeno[50];       //Jmeno
		char Prijmeni[50];    //Prijmeni
		char Heslo[50];       //Heslo prihlaseni
		char Email[100];      //Email
		TDateTime DatNar;     //Datum narozeni
		char Mesto[50];       //Mesto
		char Adresa[100];     //Adresa
		int  CisPop;          //Cislo popisne
		char PSC[20];         //PSC
		char TelCis[30];      //Telefonni cislo

		__fastcall TLog();
		__fastcall TLog(unsigned Id,String Jmeno,String Prijmeni,String Heslo,
										String Email,int DenNar,int MesNar,int RokNar,String Mesto,
										String Adresa,int CisPop,String PSC ,String TelCis);

		void __fastcall UpravLog( String Jmeno,String Prijmeni,String Heslo,String Email,
														int DenNar,int MesNar,int RokNar,String Mesto,
														String Adresa,int CisPop,String PSC ,String TelCis)
		{
			strncpy(this->Jmeno,Jmeno.c_str(),sizeof(this->Jmeno)-1);
			this->Jmeno[sizeof(this->Jmeno)-1]=0;
			strncpy(this->Prijmeni,Prijmeni.c_str(),sizeof(this->Prijmeni)-1);
			this->Prijmeni[sizeof(this->Prijmeni)-1]=0;
			strncpy(this->Heslo,Heslo.c_str(),sizeof(this->Heslo)-1);
			this->Heslo[sizeof(this->Heslo)-1]=0;
			strncpy(this->Email,Email.c_str(),sizeof(this->Email)-1);
			this->Email[sizeof(this->Email)-1]=0;
			DatNar = TDateTime(RokNar,MesNar,DenNar);
			strncpy(this->Mesto,Mesto.c_str(),sizeof(this->Mesto)-1);
			this->Mesto[sizeof(this->Mesto)-1]=0;
			strncpy(this->Adresa,Adresa.c_str(),sizeof(this->Adresa)-1);
			this->Adresa[sizeof(this->Adresa)-1]=0;
			this -> CisPop = CisPop;
			strncpy(this->PSC,PSC.c_str(),sizeof(this->PSC)-1);
			this->PSC[sizeof(this->PSC)-1]=0;
			strncpy(this->TelCis,TelCis.c_str(),sizeof(this->TelCis)-1);
			this->TelCis[sizeof(this->TelCis)-1]=0;
		}
};
#endif

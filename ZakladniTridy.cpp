#include "ZakladniTridy.h"
//---------------------------------------------------------------------------
__fastcall TLog :: TLog(unsigned Id,String Jmeno,String Prijmeni,String Heslo,
                        String Email,int DenNar,int MesNar,int RokNar,String Mesto,
                        String Adresa,int CisPop,String PSC ,String TelCis)
{
  	this -> Id = Id;
    // tedt jsem zase objevil, ze se strncpy je to trochu jinak. Viz. help:
    // char *strncpy(char *dest, char *src, int maxlen);
    // "strncpy copies up to maxlen characters from src into dest, truncating or null-padding dest.
    // The target string, dest, might not be null-terminated if the length of src is maxlen or more."
    // Vyzkousejte si to na tomto prikladu:
		// char text[100]="xxxxxxxxxxxxxxxxxxxx";
    // strncpy(text,"123456789",5);
    // printf(text);
		////////// by p.uc. Stanke
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
//---------------------------------------------------------------------------
__fastcall TLog :: TLog()
{
	Id=0;
	strcpy(Jmeno,"Jméno");            //Zadani nesmyslnych udaju
	strcpy(Prijmeni,"Pøijmení");
	strcpy(Heslo,"Heslo");
	strcpy(Email,"Email@em.em");
	DatNar=Date();                  //Dnesni datum
	strcpy(Mesto,"Mìsto");
	strcpy(Adresa,"Adresa");
	CisPop=-1;
	strcpy(PSC,"-1");
	strcpy(TelCis,"-1");
}
//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("form_prihlaseni.cpp", formPrihlaseni);
USEFORM("form_bookmaker.cpp", formBookmaker);
USEFORM("form_registrace.cpp", formRegistrace);
USEFORM("form_uzivatel.cpp", formUzivatel);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TformPrihlaseni), &formPrihlaseni);
		Application->CreateForm(__classid(TformBookmaker), &formBookmaker);
		Application->CreateForm(__classid(TformRegistrace), &formRegistrace);
		Application->CreateForm(__classid(TformUzivatel), &formUzivatel);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

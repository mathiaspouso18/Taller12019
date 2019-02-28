#include "Termino.h"

char DarSigno(Termino term){
	return term.signo;
}

int DarExponente(Termino term){
	return term.exponente;
}

int DarBase(Termino term){
	return term.base;
}

void CrearTermino(Termino &t, int base, int exp, char signo)
{
    t.signo = signo;
    t.base = base;
    t.exponente = exp;
}

void ConvertirTerminoAString(Termino term, String &s)
{
	char signo = DarSigno(term);
	int base = DarBase(term), i = 0;
	String sbase;


    if (signo == '-' )
        StrCon(s,"-");
	IntToString(sbase,base);
	StrCon(s,sbase);

}

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
	char signo = term.signo;
	int base = term.base;
	String sbase;


    if (signo == '-')
        StrCon(s, "-");
	IntToString(sbase,base);
	StrCon(s,sbase);
}


void ModificarTerminoEnLista(Termino &term, int base, int exp, char signo)
{
    term.base = base;
    term.exponente = exp;
    term.signo = signo;
}


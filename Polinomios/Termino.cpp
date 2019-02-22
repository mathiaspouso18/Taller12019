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

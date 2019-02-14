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



void Levantar_Termino (Termino &term, FILE * f)
{
	fread (&term.signo, sizeof(char), 1, f);
	fread (&term.exponente, sizeof(int), 1, f);
	fread (&term.base, sizeof(int), 1, f);
}

#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "String.h"

typedef struct { char signo;
			 int base;
			 int exponente;} Termino;


char DarSigno(Termino term);
int DarExponente(Termino term);
int DarBase(Termino term);
void CrearTermino(Termino &t, int base, int exp, char signo);
void ConvertirTerminoAString(Termino term, String &s);
void ModificarTerminoEnLista(Termino &term, int base, int exp, char signo);

#endif // TERMINO_H_INCLUDED

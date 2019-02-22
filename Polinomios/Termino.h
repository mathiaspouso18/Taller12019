#ifndef TERMINO_H_INCLUDED
#define TERMINO_H_INCLUDED

#include "String.h"

typedef struct { char signo;
			 int base;
			 int exponente;} Termino;


char DarSigno(Termino term);
int DarExponente(Termino term);
int DarBase(Termino term);
void Guardar_Termino(Termino term, FILE * f);
void Levantar_Termino(Termino &term, FILE * f);
Termino ConvertirStringATermino (String s);
void CrearTermino(Termino &t, int base, int exp, char signo);

#endif // TERMINO_H_INCLUDED

#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodo_termino{ Termino info;
               nodo_termino * sig;} Nodo;
typedef Nodo * ListaTerm;

int CantTerminos(ListaTerm lista);

void InsTermBack(ListaTerm &lista, Termino term);

void GuardarListaTerminos(ListaTerm lista, FILE *f);

void LevantarListaTerminos(ListaTerm &lista, FILE *f);

#endif // LISTATERMINOS_H_INCLUDED

#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodo_termino{ Termino info;
               nodo_termino * sig;} Nodo;
typedef Nodo * ListaTerm;

int CantTerminos(ListaTerm lista);

void InsTermBack(ListaTerm &lista, Termino term);

//void Parsear(String s, ListaTerm &lista); //Consultar si esta bien que este aca

#endif // LISTATERMINOS_H_INCLUDED

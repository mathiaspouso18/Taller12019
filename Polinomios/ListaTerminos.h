#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodo_termino{ Termino info;
               nodo_termino * sig;} Nodo;
typedef Nodo * ListaTerm;

int CantTerminos(ListaTerm lista);
void InsTermBack(ListaTerm &lista, Termino term);

void MostrarTerminos(ListaTerm l);
void BajarTerm(ListaTerm lista, String nomArch);
void LiberarListaTerm(ListaTerm &l);
void InicializarListaTerm(ListaTerm &l);
void SiguienteNodo(ListaTerm &l);
void ReducirListaTerm(ListaTerm &l);
#endif // LISTATERMINOS_H_INCLUDED

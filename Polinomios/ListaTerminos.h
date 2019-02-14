#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"

typedef struct nodo_termino{ Termino info;
               nodo_termino * sig;} Nodo;
typedef Nodo * ListaTerm;

#endif // LISTATERMINOS_H_INCLUDED

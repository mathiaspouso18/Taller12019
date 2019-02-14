#ifndef LISTAPARAMETROS_H_INCLUDED
#define LISTAPARAMETROS_H_INCLUDED
#include "String.h"


typedef struct nodo_string{String info;
			   nodo_string * sig;} Nodo;
typedef Nodo * ListaParam;

int CantParametros(ListaParam l);
#endif // LISTAPARAMETROS_H_INCLUDED

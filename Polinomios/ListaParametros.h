#ifndef LISTAPARAMETROS_H_INCLUDED
#define LISTAPARAMETROS_H_INCLUDED

#include "EnumComandos.h"
#include "String.h"


typedef struct nodo_string{String info;
			   nodo_string * sig;
				} NodoS;
typedef NodoS * ListaParam;

int CantParametros(ListaParam l);

void Parsear(String s, ListaParam &l);

void InsBack(String s, ListaParam &l);

#endif // LISTAPARAMETROS_H_INCLUDED

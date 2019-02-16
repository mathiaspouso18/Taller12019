#include "stdafx.h"
#include "ListaParametros.h"

int CantParametros(ListaParam l){
	int cant = 0;
	while(l != NULL){
		cant++;
		l = l->sig;
	}
	return cant;
}
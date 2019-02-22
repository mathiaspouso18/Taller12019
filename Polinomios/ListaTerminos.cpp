
#include "ListaTerminos.h"

int CantTerminos(ListaTerm lista){
	int cant = 0;
	while(lista != NULL){
		cant++;
		lista=lista->sig;
	}
	return cant;
}

void InsTermBack(ListaTerm &lista, Termino term){
	 if (lista == NULL)
     {
         lista = new Nodo;
         lista -> info = term;
         lista -> sig = NULL;
     }
     else
        InsTermBack (lista -> sig, term);
}

void GuardarListaTerminos(ListaTerm lista, FILE *f)
{
	while(lista != NULL)
	{
		Guardar_Termino(lista->info, f);
		lista = lista -> sig;
	}
}

void LevantarListaTerminos(ListaTerm &lista, FILE *f)
{
	Termino term;
	Levantar_Termino (term, f);
    while (!feof(f))
	{
		InsTermBack(lista, term);
		Levantar_Termino (term, f);
	}
}

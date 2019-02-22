
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

void MostrarTerminos(ListaTerm l)
{
    char signo;
    int base = 0, exponente = 0;
    while(l != NULL)
    {
        signo = DarSigno(l->info);
        base = DarBase(l->info);
        exponente = DarExponente(l->info);

        if(base > 0)
        {
            printf("%c", signo);
            printf("%d",base);

            if(exponente > 1)
            {
                printf("x");
                printf("%d ", exponente);
            }
            else if(exponente == 1)
            {
                printf("x ");
            }
        }

        l = l->sig;
    }
}

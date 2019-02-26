
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

void MostrarTerminos(ListaTerm l)
{
    char signo;
    int base = 0, exponente = 0;
    while(l != NULL)
    {
        signo = DarSigno(l->info);
        base = DarBase(l->info);
        exponente = DarExponente(l->info);

        if(base != 0)
        {
            printf("%c", signo);

            if(base != 1)
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
            else if(exponente == 0 && base == 1)
                printf("%d",base);
        }

        l = l->sig;
    }
}

void BajarTerm(ListaTerm lista, String nomArch)
{
	FILE *f = fopen (nomArch, "wb");
	while(lista != NULL)
	{
		char signo = DarSigno(lista->info), espacio = ' ';

		int base = DarBase(lista->info);
		String s;
		IntToString(s,base);

		fwrite (&signo, sizeof(char), 1, f);
		Guardar_String(s,f); //El guardar string le pone el \0, no deberia?
		fwrite (&espacio, sizeof(char), 1, f);
		lista = lista->sig;
	}

	fclose (f);
}


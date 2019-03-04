
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
    int suma = 0;
    while(l != NULL)
    {
        signo = DarSigno(l->info);
        base = DarBase(l->info);
        exponente = DarExponente(l->info);

        if(base != 0)
        {
            suma = suma + base;

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

    if(suma == 0)
        printf("0");
}

void BajarTerm(ListaTerm lista, String nomArch)
{
	FILE *f = fopen (nomArch, "wb");
	String str;
	StrCrear(str);
	int i = 0,largo = 0;
	while(lista != NULL)
	{
		ConvertirTerminoAString(lista->info,str);
		if (lista->sig != NULL)
            StrCon(str," ");
		lista = lista->sig;
	}

	Guardar_String(str,f);

	fclose (f);
}

void LiberarLista(ListaTerm &l)
{
    if(l != NULL)
    {
        LiberarLista(l -> sig);
        delete (l);
        l = NULL;
    }
}

void InicializarLista(ListaTerm &l)
{
    l = NULL;
}

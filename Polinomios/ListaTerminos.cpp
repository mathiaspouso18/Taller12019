
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

void LiberarListaTerm(ListaTerm &l)
{
    if(l != NULL)
    {
        LiberarListaTerm(l -> sig);
        delete (l);
        l = NULL;
    }
}

void InicializarListaTerm(ListaTerm &l)
{
    l = NULL;
}

void SiguienteNodo(ListaTerm &l)
{
    ListaTerm aux = l;
    l = l -> sig;
    delete aux;
}

void InsertarTerminoOrdenado(ListaTerm &l, Termino t)
{
    ListaTerm n;
    ListaTerm newNodo;
    int baseA = 0, baseB = 0;
    char signoNuevo;

    //Si no hay terminos, o el que esta en la lista es mas chico, lo inserto primero...
    if (l == NULL || DarExponente(l->info) < DarExponente(t))
    {
        newNodo = new Nodo;
        newNodo->info = t;
        newNodo->sig = l;
        l = newNodo;
    }
    else
    {
        n = l;

        while (n->sig != NULL && DarExponente(n->sig->info) >= DarExponente(t))
            n = n->sig;

        if(n != NULL && DarExponente(n->info) == DarExponente(t))
        {
            baseA = DarBase(n->info);
            baseB = DarBase(t);
            if(DarSigno(n->info) == '-')
                baseA = baseA * -1;
            if(DarSigno(t) == '-')
                baseB = baseB * -1;

            int baseNueva = baseA + baseB;
            if(baseNueva < 0)
            {
                baseNueva = baseNueva * -1;
                signoNuevo = '-';
            }
            else
            {
                signoNuevo = '+';
            }

            ModificarTerminoEnLista(n->info, baseNueva, DarExponente(t), signoNuevo);
        }
        else
        {
            newNodo = new Nodo;
            newNodo->info = t;
            newNodo->sig = n->sig;
            n->sig = newNodo;
        }
    }
}


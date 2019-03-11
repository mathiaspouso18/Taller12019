
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

void ReducirListaTerm(ListaTerm &lista){
    ListaTerm aux, l;

    Termino term;
    int exp1, exp2, base1,base2,base3;
    char signo1, signo2,signo3;
    InicializarListaTerm(aux);
    l = lista;
    while(l != NULL ){
            exp1 = DarExponente(l->info);
            base1 = DarBase(l->info);
            signo1 = DarSigno(l->info);
            if (signo1 == '-' )
                base1 = base1 * -1;

            if (l->sig != NULL){
                aux = l->sig;
                exp2 = DarExponente(aux->info);
                base2 = DarBase(aux->info);
                signo2 = DarSigno(aux->info);
                if (signo2 == '-')
                    base2 = base2 * -1;

                if (exp1 == exp2){
                    //Defino nuevo termino
                    base3=base1+base2;
                    if ( base3 < 0 ){
                        signo3 = '-';
                        base3 = base3 * -1;
                    }
                    else
                        signo3 = '+';

                    CrearTermino(term,base3,exp1,signo3);

                    //Agrego el termino a la lista
                    //******ESTA MAL ACA***//
                    delete (l);
                    l = new Nodo;
                    l->info=term;
                    l->sig = aux->sig;
                    delete (aux);
                }
            }
            l=l->sig;
    }

}


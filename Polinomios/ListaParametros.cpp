
#include "ListaParametros.h"

int CantParametros(ListaParam l){
	int cant = 0;
	while(l != NULL){
		cant++;
		l = l->sig;
	}
	return cant;
}

void InsBack(String s, ListaParam &l)
{
    if (l == NULL)
     {
         l = new NodoS;
         StrCop(l -> info, s);
         l -> sig = NULL;
     }
     else
        InsBack (s, l -> sig);
 }

 void InsFront(String s, ListaParam &l)
{
    ListaParam aux = new NodoS;
    StrCop(aux->info, s);
    aux -> sig = l;
    l = aux;
 }

void Parsear(String s, ListaParam &l)
{
	int i = 0, j = 0;
    String s1 = new char[MAX];
    Boolean anteriorLetra = FALSE;

    while(s[i] != '\0')
    {
        if(EsCaracterValido(s[i]) || s[i] == '-')
        {
            s1[j] = s[i];
            j++;
            anteriorLetra = TRUE;
        }
        else
        {
            if(anteriorLetra)
            {
                s1[j] = '\0';
                InsBack(s1,l);
                j=0;
            }
            anteriorLetra = FALSE;
        }
        i++;
    }

    s1[j] = s[i];
    s1[j+1] = '\0';
    InsBack(s1,l);
}

void SiguienteNodo(ListaParam &l)
{
    ListaParam aux = l;
    l = l -> sig;
    delete aux;
}

void LiberarListaParam(ListaParam &l)
{
    if(l != NULL)
    {
        LiberarListaParam(l -> sig);
        delete (l);
        l = NULL;
    }
}

void InicializarListaParam(ListaParam &l)
{
    l = NULL;
}

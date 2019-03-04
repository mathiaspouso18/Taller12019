
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
	String s1;
	StrCrear(s1);
	int i = 0, j = 0;

	while(s[i] == ' ')
        i++;

	while(s[i + 1] != '\0')
    {
		if(s[i] != ' ')
        {
			s1[j] = s[i];
            j++;
        }
		else
		{
                s1[j] = '\0';
                InsBack(s1,l);
                StrCrear(s1);
                while(s[i] == ' ')
                    i++;
                j=0;
                i--;
		}
        i++;
	}
	s1[j] = s[i];
    s1[j+1] = '\0';
	InsBack(s1,l);
	delete[] s1;
}

void LiberarLista(ListaParam &l)
{
    if(l != NULL)
    {
        LiberarLista(l -> sig);
        delete (l);
        l = NULL;
    }
}

void SiguienteNodo(ListaParam &l)
{
    ListaParam aux = l;
    l = l -> sig;
    delete aux;
}

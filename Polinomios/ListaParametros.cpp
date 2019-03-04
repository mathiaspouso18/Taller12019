
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
                //StrDestruir(s1);
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
	StrDestruir(s1);
}


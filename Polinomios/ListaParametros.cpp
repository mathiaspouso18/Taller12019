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

void InsFront (String s, ListaParam &l)
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
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] != ' ')
			s1[i] = s[i];
		else{
			s1[i] = '\0';
			InsFront(s,l);
			StrCrear(s1); 
		}
	}

}
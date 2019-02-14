#include "String.h"
#include "Boolean.h"
#include <stdio.h>

void StrCrear (String & s){
    s = new char[1];
    s[0] = '\0';
}

void StrDestruir (String &s){
    delete [] s;
    s = NULL;
}

int StrLar (String s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void StrCop (String &s1,String s2){
    int i = 0;
    int largo = StrLar(s2) + 1;
    //delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void Scan (String &s){
    String aux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while ((c!= '\n' && i < MAX-1)){
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StrCop (s,aux);
    StrDestruir (aux);
}

void StrCon (String &s1,String s2)
{
     String aux;
     StrCrear(aux);
     StrCop(aux, s1);
     int largo = StrLar(s1) + StrLar(s2) + 1;
     if (largo > MAX)
     largo = MAX;

     delete [] s1;
     s1 = new char[largo];
     int i = 0;
     while (aux[i] != '\0')     {
         s1[i] = aux[i];
         i++;
     }
     int j = 0;
     while (s2[j] != '\0' && i < MAX-1){
         s1[i] = s2[j];
         i++;
         j++;
     }
     s1[i] = '\0';
     StrDestruir(aux);
}

void StrSwp (String &s1, String &s2){
    String aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void Print (String s){
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

Boolean StrEq(String s1, String s2)
{
	int i = 0;
	Boolean iguales = TRUE;

	while(iguales && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		if(s1[i] != s2[i])
			iguales = FALSE;
		i++;
	}

	if((s1[i] != '\0') || (s2[i] != '\0'))
		iguales = FALSE;

	return iguales;
}

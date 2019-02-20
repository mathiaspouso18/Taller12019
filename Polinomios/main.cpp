#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

int main()
{
    ListaParam l = NULL;
    String s;

    printf("Ingrese un string a Parsear: ");
    Scan(s);
    //Prueba de Parsear()
    Parsear(s, l);

    while(l != NULL)
    {
        Print(l->info);
        printf("\n");
        l = l->sig;
    }
}

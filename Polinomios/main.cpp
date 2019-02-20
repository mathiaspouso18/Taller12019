#include <iostream>
#include "ABBPolinomio.h"


/*void PruebaParsear(ListaParam l, String s)
{
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
}*/

void PruebaValidarComando()
{
    ListaParam l = NULL;
    String s;
    printf("Ingrese un string a Parsear: ");
    Scan(s);
    Parsear(s, l);
    if(ValidarComando(l->info) == OK)
        printf("OK");
}

int main()
{
    //PruebaParsear(l, s);
    PruebaValidarComando();
}

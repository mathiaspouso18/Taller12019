#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

void PruebaParsear(ListaParam l, String s)
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

}

int main()
{


    ListaParam l = NULL;
    String s;

    //PruebaParsear(l, s);

    printf("Ingrese un string a Parsear: ");
    Scan(s);
    Parsear(s,l);


    //PRUEBA ValidarComando
    if ( ValidarComando(l->info) == OK )
        printf("OK. Continuo");
    else
        MostrarMensaje(COMANDO_INVALIDO);




}

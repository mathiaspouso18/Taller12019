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

void PruebaValidar(ListaParam l, String s)
{
    printf("Ingrese un string a Parsear: ");
    Scan(s);
    Parsear(s,l);

    if ( ValidarComando(l->info) == OK)
        printf("OK. Continuo");
    else
        MostrarMensaje(COMANDO_INVALIDO);
}

int main()
{
    Arbol abb;
    ListaParam l = NULL;
    String s;
    Polinomio p;
    EnumComandos ec;
    InicializarArbol(abb);
    int x;

    printf("Ingrese comando: ");
    Scan(s);
    Parsear(s, l);
    ec = ValidarComando(l->info);
    l = l->sig;

    //Vuelvo a solicitar un comando hasta que indique que quiere salir
    while(ec != SALIR)
    {
        switch(ec)
        {
            case CREAR:
                if(l != NULL)
                {
                    if(ExistePolinomio(abb, l->info) == NO_EXISTE_POLINOMIO)
                    {
                        if(EsValidoNombre(l->info) == OK)
                        {
                            Crear(p, l);
                            InsPoliABBPoli(abb, p);
                            MostrarMensaje(OK);
                        }
                        else
                        {
                            MostrarMensaje(NOMBRE_INVALIDO);
                        }
                    }
                    else
                    {
                        MostrarMensaje(YA_EXISTE);
                    }
                }
                else
                {
                    MostrarMensaje(NO_INGRESO_NOMBRE);
                }
            break;
            case SUMAR:
                Polinomio resu, a, b;
                a = DarPolinomio(abb, l->info);
                l = l->sig;
                b = DarPolinomio(abb, l->info);
                SumarPoli(a, b, resu);
                InsPoliABBPoli(abb, resu);
                MostrarMensaje(OK);
                break;
            case EVALUAR:
                if(CantParametros(l) == 2)
                {
                    if(EsValidoNombre(l->info) == OK)
                    {
                        if(ExistePolinomio(abb,l->info) == NO_EXISTE_POLINOMIO)
                        {
                            p = DarPolinomio(abb,l->info);
                            l=l->sig;
                            if(EsValidoNumero(l->info) == OK)
                            {
                                x = ConvertirCharANumero(l->info);
                                //Reutilizo x
                                x = EvaluarPoli(p, x);
                                printf("Resultado = %d", x);
                            }
                            else
                            {
                                MostrarMensaje(NUMERO_INVALIDO);
                            }
                        }
                        else
                        {
                            MostrarMensaje(NO_EXISTE_POLINOMIO);
                        }
                    }
                    else
                    {
                        MostrarMensaje(NOMBRE_INVALIDO);
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            case MOSTRAR:
                break;
            case SALIR:
                break;
            default:
                MostrarMensaje(COMANDO_INVALIDO);
            break;
        }

        l = NULL;
        printf("\n\n");
        printf("Ingrese comando: ");
        Scan(s);
        Parsear(s, l);
        ec = ValidarComando(l->info);
        l = l->sig;
    }
}

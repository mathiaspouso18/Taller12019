#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

int main()
{
    Arbol abb;
    ListaParam l = NULL;
    String s, nombreNuevo, strArchivo;
    Polinomio p, resu, a, b;
    EnumComandos ec;
    InicializarArbol(abb);
    int x, z;

    printf("Ingrese comando: ");
    Scan(s);
    Parsear(s, l);
    ec = ValidarComando(l->info);
    SiguienteNodo(l);

    //Vuelvo a solicitar un comando hasta que indique que quiere salir
    while(ec != SALIR)
    {
        switch(ec)
        {
            case CREAR:
                if(CantParametros(l) >= 2)
                {
                    if(l != NULL)
                    {
                        if(!ExistePolinomio(abb, l->info))
                        {
                            if(EsValidoNombre(l->info))
                            {
                                Crear(p, l);
                                InsPoliABBPoli(abb, p);
                                MostrarPolinomio(p);
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
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
            break;
            case SUMAR:
                if(CantParametros(l) == 3)
                {
                    if(!ExistePolinomio(abb, l->info))
                    {
                        if(EsValidoNombre(l->info))
                        {
                            StrCop(nombreNuevo,l->info);
                            SiguienteNodo(l);
                            if(ExistePolinomio(abb, l->info))
                            {
                                a = DarPolinomio(abb, l->info);
                                SiguienteNodo(l);
                                if(ExistePolinomio(abb, l->info))
                                {
                                    b = DarPolinomio(abb, l->info);
                                    SumarPoli(a, b, resu, nombreNuevo);
                                    MostrarPolinomio(resu);
                                    InsPoliABBPoli(abb, resu);
                                }
                                else
                                {
                                    MostrarMensaje(NO_EXISTE_POLINOMIO);
                                }
                            }
                            else
                            {
                                MostrarMensaje(NO_EXISTE_POLINOMIO);
                            }
                         }
                        else
                            MostrarMensaje(NOMBRE_INVALIDO);
                    }
                    else
                    {
                        MostrarMensaje(YA_EXISTE);
                    }
                }
                else
                    MostrarMensaje(PARAMETROS_INVALIDOS);
            break;
            case MULTIPLICAR:
                if (CantParametros(l) == 3)
                {
                    if(EsValidoNombre(l->info))
                    {
                        if(!ExistePolinomio(abb,l->info))
                        {
                            StrCop(nombreNuevo,l->info);
                            SiguienteNodo(l);
                            if(EsValidoNombre(l->info))
                            {
                                if(ExistePolinomio(abb,l->info))
                                {
                                    a = DarPolinomio(abb,l->info);
                                    SiguienteNodo(l);
                                    if(EsValidoNombre(l->info))
                                    {
                                        if(ExistePolinomio(abb,l->info))
                                        {
                                            b = DarPolinomio(abb,l->info);
                                            MultiplicarPoli(a,b,resu,nombreNuevo);
                                            MostrarPolinomio(resu);
                                            InsPoliABBPoli(abb, resu);
                                        }
                                        else
                                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                                    }
                                    else
                                        MostrarMensaje(NOMBRE_INVALIDO);
                                }
                                else
                                    MostrarMensaje(NO_EXISTE_POLINOMIO);
                            }
                            else
                                MostrarMensaje(NOMBRE_INVALIDO);
                        }
                        else
                            MostrarMensaje(YA_EXISTE);
                    }
                    else
                        MostrarMensaje(NOMBRE_INVALIDO);
                }
                else
                    MostrarMensaje(PARAMETROS_INVALIDOS);
            break;
            case EVALUAR:
                if(CantParametros(l) == 2)
                {
                    if(ExistePolinomio(abb,l->info))
                    {
                        p = DarPolinomio(abb,l->info);
                        SiguienteNodo(l);
                        if(EsValidoNumero(l->info))
                        {
                            x = ConvertirCharANumero(l->info);
                            if(l->info[0] == '-')
                                x = x * -1;
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
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            case ES_RAIZ:
                if(CantParametros(l) == 2)
                {
                    if(ExistePolinomio(abb,l->info))
                    {
                        p = DarPolinomio(abb,l->info);
                        SiguienteNodo(l);
                        if(EsValidoNumero(l->info))
                        {
                            z = ConvertirCharANumero(l->info);
                            if(l->info[0] == '-')
                                z = z * -1;
                            x = EvaluarPoli(p, z);
                            if(x == 0)
                                printf("%d es raiz del polinomio", z);
                            else
                                printf("%d NO es raiz del polinomio", z);
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
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            case MOSTRAR:
                if(abb != NULL)
                    MostrarABBPoli(abb);
                else
                    MostrarMensaje(ABB_VACIO);
                break;
            case GUARDAR:
				if(CantParametros(l) == 2)
                {
					if(ExistePolinomio(abb,l->info))
                    {
						p = DarPolinomio(abb,l->info);
                        SiguienteNodo(l);
                        ListaTerm lista;
						DarListaTermPoli(p,lista);
						BajarTerm(lista,l->info);
						printf("polinomio almacenado correctamente en ");
						x = 0;
						StrCop(s,l->info);
						while(s[x] != '\0')
						{
							printf("%c", s[x]);
							x++;
						}
					}
                    else
                    {
                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                    }
				}
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            case RECUPERAR:
                if(CantParametros(l) == 2)
                {
                    Polinomio p;
					if(!ExistePolinomio(abb,l->info))
                    {
                        StrCrear(strArchivo);
                        StrCop(nombreNuevo,l->info);
                        SiguienteNodo(l);
                        if (EsValidoNombre(l->info)){
                            // A TERMINAR EXPOTA!!!
                            Levantar_String(strArchivo,l->info);
                            //ListaParam l2 = NULL;
                            //Parsear(strArchivo, l2);
                            //InsFront(nombreNuevo, l2);
                            //Crear(p, l2);
                            //InsPoliABBPoli(abb, p);
                            //MostrarPolinomio(p);
                            Print(strArchivo);
                        }
                    }
                    else
                        MostrarMensaje(YA_EXISTE);
                }
                else
                    MostrarMensaje(PARAMETROS_INVALIDOS);

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
        SiguienteNodo(l);
    }
	LiberarMemoriaABB(abb);
	printf("\nResultado = Hasta la proxima");
}

#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

int main()
{
    Arbol abb;
    ListaParam l;
    String s, cmd;
    Polinomio p, resu, a, b;
    EnumComandos ec;
    InicializarArbol(abb);
    InicializarLista(l);
    int x, z;

    MostrarMensaje(BIENVENIDA);
    MostrarMensaje(INGRESO);
    Scan(s);
    Parsear(s, l);
    StrCop(cmd, l->info);
    LowerCase(cmd);
    ec = ValidarComando(cmd);
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
                                printf("\n");
                            }
                        }
                        else
                        {
                            MostrarMensaje(YA_EXISTE);
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(NO_INGRESO_NOMBRE);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
            break;
            case SUMAR:
                if(CantParametros(l) == 3)
                {
                    String nombreNuevo;
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
                                    printf("\n");
                                }
                            }
                            else
                            {
                                MostrarMensaje(NO_EXISTE_POLINOMIO);
                                printf("\n");
                            }
                         }
                        else
                        {
                            MostrarMensaje(NOMBRE_INVALIDO);
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(YA_EXISTE);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
            break;
            case MULTIPLICAR:
                if (CantParametros(l) == 3)
                {
                    String nombreNuevo;
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
                                        {
                                            MostrarMensaje(NO_EXISTE_POLINOMIO);
                                            printf("\n");
                                        }
                                    }
                                    else
                                    {
                                        MostrarMensaje(NOMBRE_INVALIDO);
                                        printf("\n");
                                    }
                                }
                                else
                                {
                                    MostrarMensaje(NO_EXISTE_POLINOMIO);
                                    printf("\n");
                                }
                            }
                            else
                            {
                                MostrarMensaje(NOMBRE_INVALIDO);
                                printf("\n");
                            }
                        }
                        else
                        {
                            MostrarMensaje(YA_EXISTE);
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(NOMBRE_INVALIDO);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
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
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
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
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
                break;
            case MOSTRAR:
                if(abb != NULL)
                    MostrarABBPoli(abb);
                else
                {
                    MostrarMensaje(ABB_VACIO);
                    printf("\n");
                }
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
						MostrarMensaje(GUARDADO);
						Print(l->info);
						printf("\n");
					}
                    else
                    {
                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                        printf("\n");
                    }
				}
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
                break;
            case RECUPERAR:
                if(CantParametros(l) == 2)
                {
                    String strArchivo, nombreNuevo;
                    Polinomio p;
					if(!ExistePolinomio(abb,l->info))
                    {
                        StrCrear(strArchivo);
                        StrCop(nombreNuevo,l->info);
                        SiguienteNodo(l);
                        if (EsValidoNombre(l->info)){
                            Levantar_String(strArchivo,l->info);
                            ListaParam l2 = NULL;
                            Parsear(strArchivo, l2);
                            InsFront(nombreNuevo, l2);
                            Crear(p, l2);
                            InsPoliABBPoli(abb, p);
                            MostrarPolinomio(p);
                        }
                        else
                        {
                            MostrarMensaje(NOMBRE_INVALIDO);
                            printf("\n");
                        }
                    }
                    else
                    {
                        MostrarMensaje(YA_EXISTE);
                        printf("\n");
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                    printf("\n");
                }
                break;
            default:
                MostrarMensaje(COMANDO_INVALIDO);
                printf("\n");
            break;
        }

        LiberarLista(l);
        MostrarMensaje(INGRESO);
        Scan(s);
        Parsear(s, l);
        StrCop(cmd, l->info);
        LowerCase(cmd);
        ec = ValidarComando(cmd);
        SiguienteNodo(l);
    }
	LiberarMemoriaABB(abb);
	MostrarMensaje(CERRAR);
}

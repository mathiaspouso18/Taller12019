#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

int main()
{
    Arbol abb;
    ListaParam l, aux;
    String s, cmd;
    Polinomio p, resu, a, b;
    EnumComandos ec;
    InicializarArbol(abb);
    InicializarLista(l);
    InicializarLista(aux);
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
                            	aux = l->sig;
				Boolean esValidoNum = TRUE;
				while(aux != NULL && esValidoNum)
				{
					esValidoNum = EsValidoNumero(aux->info);
					aux = aux->sig;
				}
				if(esValidoNum)
				{
					Crear(p, l);
					InsPoliABBPoli(abb, p);
					MostrarPolinomio(p);
				}
				else
				{
				MostrarMensaje(NUMERO_INVALIDO);
				}
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
                        MostrarMensaje(YA_EXISTE);
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
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
                                        }
                                    }
                                    else
                                    {
                                        MostrarMensaje(NOMBRE_INVALIDO);
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
                            MostrarMensaje(YA_EXISTE);
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
                            printf("Resultado = %d\n", x);
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
                                printf("%d es raiz del polinomio\n", z);
                            else
                                printf("%d NO es raiz del polinomio\n", z);
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
                {
                    MostrarMensaje(ABB_VACIO);
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
                    String strArchivo, nombreNuevo;
                    Polinomio p;
					if(!ExistePolinomio(abb,l->info))
                    {
                        StrCrear(strArchivo);
                        StrCop(nombreNuevo,l->info);
                        SiguienteNodo(l);
                        if (EsValidoNombre(l->info))
                        {
                            if(ExisteArchivo(l->info))
                            {
                                Levantar_String(strArchivo,l->info);
                                ListaParam l2;
                                InicializarLista(l2);
                                Parsear(strArchivo, l2);
                                InsFront(nombreNuevo, l2);
                                Crear(p, l2);
                                InsPoliABBPoli(abb, p);
                                MostrarPolinomio(p);
                            }
                            else
                            {
                                MostrarMensaje(NO_EXISTE_ARCHIVO);
                            }
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
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            default:
                MostrarMensaje(COMANDO_INVALIDO);
            break;
        }

        InicializarLista(l);
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

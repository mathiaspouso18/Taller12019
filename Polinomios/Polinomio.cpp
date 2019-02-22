
#include "Polinomio.h"

void DarNombrePoli(Polinomio p, String &nom)
{
    StrCop(nom, p.nombre);
}

void Crear(Polinomio &p, ListaParam lista)
{
    char signo = '+';
    int base, cant_terminos = 0;
    Termino t;
    ListaTerm listaTerminos = NULL;
    if(lista != NULL)
    {
        if(EsValidoNombre(lista->info))
        {
            StrCop(p.nombre, lista->info);
            lista = lista -> sig;
            cant_terminos = CantParametros(lista) - 1;
            if(cant_terminos == 0)
            {
                MostrarMensaje(NO_INGRESO_TERMINO);
            }
            else
            {
                if(cant_terminos > 2 || (cant_terminos <= 2 && !StrEq(lista->info, "0")))
                {
                    if(EsValidoNumero(lista -> info))
                    {
                        while(lista != NULL)
                        {
                            if(lista->info[0] == '-')
                                signo = '-';

                            base = ConvertirCharANumero(lista->info);
                            CrearTermino(t, base, cant_terminos, signo);
                            InsTermBack(listaTerminos, t);
                            cant_terminos--;

                            lista = lista->sig;
                        }
                    }
                    else
                    {
                        MostrarMensaje(NUMERO_INVALIDO);
                    }
                    p.Listaterminos = listaTerminos;
                }
                else
                {
                    MostrarMensaje(NO_INGRESO_TERMINO);
                }
            }
        }
        else
        {
            MostrarMensaje(NOMBRE_INVALIDO);
        }
    }
    else
    {
        MostrarMensaje(NO_INGRESO_NOMBRE);
    }

}


void MostrarPolinomio(Polinomio p)
{
    Print(p.nombre);
    printf(" = ");
    MostrarTerminos(p.Listaterminos);
}

void GuardarPolinomio(Polinomio p, String poli)
{
	FILE *f = fopen(poli,"wb");
	ListaTerm lista;
	Guardar_String (p.nombre, f);
	//DarListaTermPoli(p, lista);
	GuardarListaTerminos(lista, f);
	fclose(f);
}

void LevantarPolinomio(Polinomio &p, String poli)
{
	FILE *f = fopen(poli,"rb");
	ListaTerm lista;
	LevantarListaTerminos(lista, f);
	Levantar_String(p.nombre,f);
	p.Listaterminos = lista;
	fclose(f);
}

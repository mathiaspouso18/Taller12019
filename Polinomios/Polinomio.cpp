
#include "Polinomio.h"

void DarNombrePloli(Polinomio p, String &nom)
{

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
            cant_terminos = CantParametros(lista);
            if(cant_terminos > 2)
            {
                if(lista->info == 0)
                {
                    MostrarMensaje(NO_INGRESO_TERMINO);
                }
                else
                {
                    while(lista != NULL)
                    {
                        if(StrEq(lista->info, "-"))
                            signo = '-';
                        else
                        {
                            base = ConvertirCharANumero(lista->info);
                            CrearTermino(t, base, cant_terminos, signo);
                            InsTermBack(listaTerminos, t);
                            lista = lista->sig;
                            cant_terminos--;
                        }
                    }
                    p.Listaterminos = listaTerminos;
                }
            }
        }
        else
        {
            MostrarMensaje(NOMBRE_INVALIDO);
        }
    }

}


/*void MostrarPolinomio(Polinomio p)
{
	int i = 1;
	ListaTerm l;
	Print(p.nombre);
	printf("= ");
	DarListaTermPoli(p, l);
	while(l != NULL){

	}

}*/

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

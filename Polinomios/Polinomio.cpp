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
            if(EsValidoNumero(lista -> info) == OK)
            {
                while(lista != NULL)
                {
                    if(lista->info[0] == '-')
                        signo = '-';

                    base = ConvertirCharANumero(lista->info);
                    CrearTermino(t, base, cant_terminos, signo);
                    InsTermBack(listaTerminos, t);
                    cant_terminos--;
                    signo = '+';
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

int EvaluarPoli(Polinomio p, int x)
{
	ListaTerm l;
	int base, exponente, resultado, temp, i;
	char signo;
	DarListaTermPoli(p, l);

	while(l != NULL){
		base = DarBase(l->info);
		signo = DarSigno(l->info);
		if(base != 0)
		{
			exponente = DarExponente(l->info);
			temp = x;
			if(exponente > 1){
				i = exponente;
				while(i > 1){
					temp = temp * x;
					i--;
				}
				temp = temp * base;
			}else{
				if(exponente == 1){
					temp = x * base;
				}
				else{
					if(exponente == 0){
						temp = base;
					}
				}
			}
		}
		if(signo == '-'){
			temp = temp * -1;
			resultado = resultado + temp;
			l = l->sig;
		}
	l = l ->sig;
	}
	return resultado;
}

void MostrarPolinomio(Polinomio p)
{
    Print(p.nombre);
    printf(" = ");
    MostrarTerminos(p.Listaterminos);
}

void DarListaTermPoli(Polinomio p, ListaTerm &lista)
{

}

void SumarPoli(Polinomio a, Polinomio b, Polinomio &resu, String nombreNuevo)
{
    int CantA = CantTerminos(a.Listaterminos);
    int CantB = CantTerminos(b.Listaterminos);
    int base = 0, exponente = 0, base2 = 0, exponente2 = 0, baseNueva = 0;
    Boolean encontre = FALSE;
    ListaTerm lista1, lista2, listaNueva = NULL;
    char signo, signo2, signoNuevo = '+';
    Termino term;

    //Esto es para saber cual recorro primero
    if(CantA >= CantB)
    {
        lista1 = a.Listaterminos;
        lista2 = b.Listaterminos;
    }
    else
    {
        lista1 = b.Listaterminos;
        lista2 = a.Listaterminos;
    }

    while(lista1 != NULL)
    {
        encontre = FALSE;
        signo = DarSigno(lista1->info);
        base = DarBase(lista1->info);
        exponente = DarExponente(lista1->info);
        if(signo == '-')
            base = base * -1;

        while(lista2 != NULL && !encontre)
        {
            exponente2 = DarExponente(lista2->info);
            if(exponente == exponente2)
            {
                encontre = TRUE;
                signo2 = DarSigno(lista2->info);
                base2 = DarBase(lista2->info);
                if(signo2 == '-')
                    base2 = base2 * -1;
                baseNueva = base + base2;
                if(baseNueva < 0)
                    signoNuevo = '-';

                CrearTermino(term, baseNueva, exponente, signoNuevo);
                InsTermBack(listaNueva, term);
            }
            lista2 = lista2->sig;
        }
        lista1 = lista1->sig;
    }

    resu.Listaterminos = listaNueva;
    StrCop(resu.nombre, nombreNuevo);
}

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
    p.Listaterminos = listaTerminos;
}


int EvaluarPoli(Polinomio p, int x)
{
	ListaTerm l = NULL;
	int base = 0, exponente = 0, resultado = 0, temp = 0, i = 0;
	char signo;
	DarListaTermPoli(p, l);

	while(l != NULL)
    {
		base = DarBase(l->info);
		signo = DarSigno(l->info);
		if(base != 0)
		{
			exponente = DarExponente(l->info);
			temp = x;
			if(exponente > 1)
			{
				i = exponente;
				while(i > 1)
				{
					temp = temp * x;
					i--;
				}
				temp = temp * base;
			}
            else
            {
				if(exponente == 1)
				{
					temp = x * base;
				}
				else
				{
					if(exponente == 0)
					{
						temp = base;
					}
				}
			}
            if(signo == '-')
                temp = temp * -1;

            resultado = resultado + temp;
		}

        l = l ->sig;
	}
	return resultado;
}

void MostrarPolinomio(Polinomio p)
{
    printf("\t- ");
    Print(p.nombre);
    printf(" = ");
    MostrarTerminos(p.Listaterminos);
    printf("\n");
}

void DarListaTermPoli(Polinomio p, ListaTerm &lista)
{
    lista = p.Listaterminos;
}

void SumarPoli(Polinomio a, Polinomio b, Polinomio &resu, String nombreNuevo)
{
    int CantA = CantTerminos(a.Listaterminos);
    int CantB = CantTerminos(b.Listaterminos);
    int base = 0, exponente = 0, base2 = 0, exponente2 = 0, baseNueva = 0;
    Boolean seguir = TRUE;
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
        seguir = TRUE;
        signo = DarSigno(lista1->info);
        base = DarBase(lista1->info);
        exponente = DarExponente(lista1->info);

        if(signo == '-')
            base = base * -1;

        while(lista2 != NULL && seguir)
        {
            exponente2 = DarExponente(lista2->info);
            if(exponente == exponente2)
            {
                seguir = FALSE;
                signo2 = DarSigno(lista2->info);
                base2 = DarBase(lista2->info);

                if(signo2 == '-')
                    base2 = base2 * -1;

                baseNueva = base + base2;

                if(baseNueva < 0)
                {
                    signoNuevo = '-';
                    baseNueva = baseNueva * -1;
                }

                CrearTermino(term, baseNueva, exponente, signoNuevo);
                signoNuevo = '+';
                InsTermBack(listaNueva, term);
                lista2 = lista2->sig;
            }
            else
            {
                InsTermBack(listaNueva, lista1->info);
                seguir = FALSE;
            }
        }
        if(lista2 == NULL && seguir)
            InsTermBack(listaNueva, lista1->info);
        lista1 = lista1->sig;
    }

    resu.Listaterminos = listaNueva;
    StrCop(resu.nombre, nombreNuevo);
}

void MultiplicarPoli(Polinomio a, Polinomio b ,Polinomio &resu, String nombreNuevo){

    ListaTerm listaA, listaB, listTemp1=NULL, listTemp2=NULL;

    int baseA=0, exponenteA=0, baseB=0, exponenteB=0, exponenteResu=0, baseResu=0;
    char signoA,signoB,signoResu;
    Termino term;
    Polinomio temp1,temp2;

    listaA = a.Listaterminos;
    listaB = b.Listaterminos;

    //Primer Recorrido
    while(listaA != NULL)
    {
        signoA = DarSigno(listaA->info);
        baseA = DarBase(listaA->info);
        exponenteA = DarExponente(listaA->info);
        while(listaB != NULL)
        {
            signoB = DarSigno(listaB->info);
            baseB = DarBase(listaB->info);
            exponenteB = DarExponente(listaB->info);

            if (exponenteA >= exponenteB)
            {
                if (baseB != 0 && baseA != 0)
                {
                    exponenteResu = exponenteA + exponenteB;
                    baseResu = baseA * baseB;
                    if (signoA == signoB)
                        signoResu = '+';
                    else
                        signoResu='-';

                    CrearTermino(term,baseResu,exponenteResu,signoResu);
                    InsTermBack(listTemp1,term);
                }
            }
            listaB = listaB->sig;
        }
        listaA=listaA->sig;
        listaB = b.Listaterminos;
    }

    //Segundo Recorrido por si el 2do polinomio es de mayor grado
    listaA = a.Listaterminos;
    listaB = b.Listaterminos;
    while(listaB != NULL)
    {
            signoB = DarSigno(listaB->info);
            baseB = DarBase(listaB->info);
            exponenteB = DarExponente(listaB->info);
            while(listaA != NULL)
            {
                signoA = DarSigno(listaA->info);
                baseA = DarBase(listaA->info);
                exponenteA = DarExponente(listaA->info);

                if (exponenteB > exponenteA)
                {
                    if (baseA != 0 && baseB != 0)
                    {
                        exponenteResu = exponenteA + exponenteB;
                        baseResu = baseA * baseB;
                        if (signoA == signoB)
                            signoResu = '+';
                        else
                            signoResu='-';

                        CrearTermino(term,baseResu,exponenteResu,signoResu);
                        InsTermBack(listTemp2,term);
                    }
                }
                listaA = listaA->sig;
            }
            listaB = listaB->sig;
            listaA = a.Listaterminos;
    }
    temp1.Listaterminos = listTemp1;
    temp1.nombre="temp1";

    temp2.Listaterminos = listTemp2;
    temp2.nombre = "temp2";

    SumarPoli(temp1,temp2,resu,nombreNuevo);
}

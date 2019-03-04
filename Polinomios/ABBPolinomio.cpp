#include "ABBPolinomio.h"


void InicializarArbol(Arbol &ABB)
{
    ABB = NULL;
}

Boolean EsVacio(Arbol ABB)
{
    Boolean es = TRUE;
    if(ABB != NULL)
        es = FALSE;

    return es;
}

Polinomio DarRaiz(Arbol ABB)
{
    return ABB->info;
}

Arbol HijoIzquierdo(Arbol ABB)
{
    return ABB->hizq;
}

Arbol HijoDerecho(Arbol ABB)
{
    return ABB->hder;
}

void InsPoliABBPoli(Arbol &abb, Polinomio p)
{
    String nombre_poli_abb, nombre_poli;
	DarNombrePoli(p, nombre_poli);

	if (abb == NULL)
    {
        abb = new nodo;
        abb -> info = p;
        abb -> hizq = NULL;
        abb -> hder = NULL;
    }
    else
    {
        DarNombrePoli(abb->info, nombre_poli_abb);
        if(!EsMayor(nombre_poli_abb, nombre_poli))
            InsPoliABBPoli (abb -> hizq, p);
        else
            InsPoliABBPoli (abb -> hder, p);
    }
}

Boolean ExistePolinomio(Arbol ABBPoli, String nombre_poli)
{
    Boolean existe = FALSE;
	String nombre_poli_abb;
	LowerCase(nombre_poli);

    while(existe != TRUE && ABBPoli != NULL){
		DarNombrePoli(ABBPoli->info, nombre_poli_abb);
		LowerCase(nombre_poli_abb);
        if(StrEq(nombre_poli, nombre_poli_abb))
        {
            existe = TRUE;
        }
        else
        {
            if(!EsMayor(nombre_poli_abb, nombre_poli))
                ABBPoli = ABBPoli->hizq;
            else
                ABBPoli = ABBPoli->hder;
        }
    }
    return existe;
}

Polinomio DarPolinomio (Arbol ABBPoli, String nombre_poli)
{
	Polinomio p;
	Boolean seguir = TRUE;
	String nombre_poli_abb;

	while(seguir)
    {
        if(ABBPoli == NULL)
        {
            seguir = FALSE;
        }
        else
        {
            DarNombrePoli(ABBPoli->info, nombre_poli_abb);
            if(StrEq(nombre_poli, nombre_poli_abb)){
                p = DarRaiz(ABBPoli);
                seguir = FALSE;
            }
            else
            {
                if(!EsMayor(nombre_poli_abb, nombre_poli))
                    ABBPoli = ABBPoli->hizq;
                else
                    ABBPoli = ABBPoli->hder;
            }
        }
	}
	return p;
}

void MostrarABBPoli(Arbol abb)
{
    if (abb != NULL)
	{
		MostrarABBPoli(abb->hizq);
		MostrarPolinomio(abb->info);
		MostrarABBPoli(abb->hder);
	}
}

void LiberarMemoriaABB (Arbol &ABB)
{
	if (ABB != NULL)
	{
		LiberarMemoriaABB(ABB -> hizq);
		LiberarMemoriaABB(ABB -> hder);
		delete (ABB);
	}
}

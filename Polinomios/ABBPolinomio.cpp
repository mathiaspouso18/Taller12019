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
	DarNombrePloli(p, nombre_poli);
	DarNombrePloli(ABBPoli->info, nombre_poli_abb);

	if (ABBPoli == NULL)
    {
        ABBPoli = new nodo;
        ABBPoli -> info = p;
        ABBPoli -> hizq = NULL;
        ABBPoli -> hder = NULL;
    }
    else
    {
        if(EsMayor(nombre_poli_abb, nombre_poli))
            InsPoliABBPoli (ABBPoli -> hizq, p);
        else
            InsPoliABBPoli (ABBPoli -> hder, p);
    }
}

TipoMensaje ExistePolinomio(Arbol &ABBPoli, String nombre_poli)
{
    TipoMensaje existe = NO_EXISTE_POLINOMIO;
	String nombre_poli_abb;

    while(existe != OK && ABBPoli != NULL){
		DarNombrePloli(ABBPoli->info, nombre_poli_abb);
        if(StrEq(nombre_poli, nombre_poli_abb))
        {
            existe = OK;
        }
        else
        {
            if(EsMayor(nombre_poli_abb, nombre_poli))
                ABBPoli = ABBPoli->hizq;
            else
                ABBPoli = ABBPoli->hder;
        }
    }
    return existe;
}

Polinomio DarPolinomio (Arbol ABBPoli, String nombre_poli){
	Polinomio p;
	Boolean encontre = FALSE;
	String nombre_poli_abb;
	
	while(!encontre){
		
		DarNombrePloli(ABBPoli->info, nombre_poli_abb);
		if(StrEq(nombre_poli, nombre_poli_abb)){
			p = DarRaiz(ABBPoli);
			encontre = TRUE;
		}
		else
		{
			if(EsMayor(nombre_poli_abb, nombre_poli))
                ABBPoli = ABBPoli->hizq;
            else
                ABBPoli = ABBPoli->hder;
		}
	}
	return p;
}

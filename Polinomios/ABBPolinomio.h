#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoN { Polinomio info;
                       nodoN *hizq;
                       nodoN *hder;} nodo;

typedef nodo *Arbol;

void InicializarArbol(Arbol &ABB);

Boolean EsVacio(Arbol ABB);

Polinomio DarRaiz(Arbol ABB);

Arbol HijoIzquierdo(Arbol ABB);

Arbol HijoDerecho(Arbol ABB);

//Precondicion: El arbol no esta vacio.
void MostrarABBPoli(Arbol ABBPoli);

void InsPoliABBPoli(Arbol &ABBPoli, Polinomio p);

Boolean ExistePolinomio(Arbol ABBPoli, String nombre_poli);

//Precondicion: El polinomio existe en el arbol.
Polinomio DarPolinomio (Arbol ABBPoli, String nombre_poli);

void LiberarMemoriaABB(Arbol &ABB);
#endif // ABBPOLINOMIO_H_INCLUDED

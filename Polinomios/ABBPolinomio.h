#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"
#include <stdio.h>

typedef struct nodoN { Polinomio info;
                       nodoN *hizq;
                       nodoN *hder;} nodo;

typedef nodo *Arbol;

void InicializarArbol(Arbol &ABB);
void MostrarABBPoli(Arbol ABBPoli);
void InsPoliABBPoli(Arbol &ABBPoli, Polinomio p);
Boolean ExistePolinomio(Arbol &ABBPoli, String nombre_poli);
void DarPolinomio (Arbol &ABBPoli, String nombre_poli);


void Bajar_ABB (Arbol ABBPoli, String nomArch)

/*Precondicion: Debe existir el archivo.*/
void Levantar_ABB (Arbol &ABB, String nomArch);

#endif // ABBPOLINOMIO_H_INCLUDED

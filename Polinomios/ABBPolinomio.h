#ifndef ABBPOLINOMIO_H_INCLUDED
#define ABBPOLINOMIO_H_INCLUDED

#include "Polinomio.h"

typedef struct nodoN { Polinomio info;
                       nodoN *hizq;
                       nodoN *hder;} nodo;

typedef nodo *Arbol;

#endif // ABBPOLINOMIO_H_INCLUDED

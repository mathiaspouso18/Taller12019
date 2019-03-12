#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"
#include "ListaParametros.h"

typedef struct nodo_int{String nombre;
                        ListaTerm Listaterminos;} Polinomio;

void DarNombrePoli(Polinomio p, String &nom);

void DarListaTermPoli(Polinomio p, ListaTerm &lista);

void Crear(Polinomio &p, ListaParam lista);

//Precondicion: Los polinomios existen.
void SumarPoli(Polinomio a, Polinomio b ,Polinomio &resu, String nombreNuevo);

//Precondicion: Los polinomios existen.
void MultiplicarPoli(Polinomio a, Polinomio b ,Polinomio &resu, String nombreNuevo);

//Precondicion: El polinomio existe.
int EvaluarPoli(Polinomio p, int x);

void MostrarPolinomio(Polinomio p);

#endif // POLINOMIO_H_INCLUDED

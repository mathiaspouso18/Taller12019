#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"
#include "ListaParametros.h"

typedef struct nodo_int{String nombre;
                        ListaTerm Listaterminos;} Polinomio;

void DarNombrePoli(Polinomio p, String &nom);
void DarListaTermPoli(Polinomio p, ListaTerm &lista);
void Crear(Polinomio &p, ListaParam lista);
void SumarPoli(Polinomio a, Polinomio b ,Polinomio &resu);
void MultiplicarPoli(Polinomio a, Polinomio b ,Polinomio &resu);
int EvaluarPoli(Polinomio p, int x);
Boolean EsRaizPoli(Polinomio p, int x);

void MostrarPolinomio(Polinomio p);

#endif // POLINOMIO_H_INCLUDED

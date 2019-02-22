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

void GuardarPolinomio(Polinomio p, String poli);

/*Precondicion: Debe existir el polinomio*/
void LevantarPolinomio(Polinomio &p, String poli);

#endif // POLINOMIO_H_INCLUDED

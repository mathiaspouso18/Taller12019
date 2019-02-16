#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "ListaTerminos.h"
#include "ListaParametros.h"

typedef struct nodo_int{String nombre;
                        ListaTerm Listaterminos;} Polinomio;

void DarNombrePloli(Polinomio p, String &nom);
void DarListaTermPoli(Polinomio p, ListaTerm &lista);
void Crear(Polinomio &p, ListaParam lista);
void SumarPoli(Polinomio a, Polinomio b ,Polinomio &resu);
void MultiplicarPoli(Polinomio a, Polinomio b ,Polinomio &resu);
int EvaluarPoli(Polinomio p, int x);
Boolean EsRaizPoli(Polinomio p, int x);

void GuardarPolinomio(Polinomio p, FILE * f);

/*Precondicion: Debe existir el polinomio*/
void RecuperarPolinomio(Polinomio &p, String poli, String archivo);

#endif // POLINOMIO_H_INCLUDED

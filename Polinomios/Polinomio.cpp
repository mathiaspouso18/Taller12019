#include "stdafx.h"
#include "Polinomio.h"


void GuardarPolinomio(Polinomio p, FILE * f)
{
	ListaTerm lista;
	Guardar_String (p.nombre, f);
	DarListaTermPoli(p, lista);
	Guardar_Termino(lista -> info, f);
}
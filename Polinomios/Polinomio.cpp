#include "Polinomio.h"


void GuardarPolinomio(Polinomio p, FILE * f)
{
	Guardar_String (DarNombrePloli(p), f);
	DarNombreEscrib(ex,nom);
	DarApellidoEscrib(ex,ape);
	Bajar_String (nom, f);
	Bajar_String (ape, f);
	fwrite (&ex.cantPags, sizeof(int), 1, f);
}

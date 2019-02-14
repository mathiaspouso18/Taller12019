#include "ABBPolinomio.h"

void Bajar_ABB (Arbol ABB, String nomArch)
{
	FILE * f = fopen (nomArch, "wb");
	GuardarPolinomio (ABB->info, f);
	fclose (f);
}

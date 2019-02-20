
#include "Polinomio.h"

void DarNombrePloli(Polinomio p, String &nom)
{

}

void Crear(Polinomio &p, ListaParam lista)
{

}


/*void MostrarPolinomio(Polinomio p)
{
	int i = 1;
	ListaTerm l;
	Print(p.nombre);
	printf("= ");
	DarListaTermPoli(p, l);
	while(l != NULL){

	}

}*/

void GuardarPolinomio(Polinomio p, String poli)
{
	FILE *f = fopen(poli,"wb");
	ListaTerm lista;
	Guardar_String (p.nombre, f);
	//DarListaTermPoli(p, lista);
	GuardarListaTerminos(lista, f);
	fclose(f);
}

void LevantarPolinomio(Polinomio &p, String poli)
{
	FILE *f = fopen(poli,"rb");
	ListaTerm lista;
	LevantarListaTerminos(lista, f);
	Levantar_String(p.nombre,f);
	p.Listaterminos = lista;
	fclose(f);
}

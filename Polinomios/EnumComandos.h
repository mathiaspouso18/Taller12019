#ifndef ENUMCOMANDOS_H_INCLUDED
#define ENUMCOMANDOS_H_INCLUDED

#include "String.h"

typedef enum{CREAR, SUMAR, MULTIPLICAR, EVALUAR, ES_RAIZ, MOSTRAR, GUARDAR, RECUPERAR, SALIR, NADA} EnumComandos;

EnumComandos ValidarComando(String s);

#endif // ENUMCOMANDOS_H_INCLUDED

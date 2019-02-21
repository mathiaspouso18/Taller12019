#include "EnumMensajes.h"
#include <stdio.h>
//OK, , , , , , } TipoMensaje;
void MostrarMensaje(TipoMensaje tipo){
    switch (tipo){
        case OK: printf("OK");break;
        case NOMBRE_INVALIDO: printf("ERROR: Nombre invalido");break;
        case NUMERO_INVALIDO: printf("ERROR: Numero invalido");break;
        case COMANDO_INVALIDO: printf("ERROR: Comando invalido");break;
        case YA_EXISTE: printf("ERROR: Ya existe polinomio");break;
        case NO_INGRESO_NOMBRE: printf("ERROR: No ingreso nombre");break;
        case NO_INGRESO_TERMINO: printf("ERROR: No ingreso termino");break;
    }
}

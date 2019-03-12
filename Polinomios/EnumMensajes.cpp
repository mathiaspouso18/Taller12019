#include "EnumMensajes.h"
#include <stdio.h>
#include "Windows.h"

void MostrarMensaje(TipoMensaje tipo){
    SetConsoleTitle("Sistema de gestion de polinomios - Taller 1");
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD OriginalColors = ConsoleInfo->wAttributes;
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);

    switch (tipo){
        case NOMBRE_INVALIDO: printf("ERROR: Nombre invalido\n");break;
        case NUMERO_INVALIDO: printf("ERROR: Numero invalido\n");break;
        case COMANDO_INVALIDO: printf("ERROR: Comando invalido\n");break;
        case YA_EXISTE: printf("ERROR: Ya existe polinomio con ese nombre\n");break;
        case NO_EXISTE_POLINOMIO: printf("ERROR: No existe polinomio con ese nombre\n");break;
        case NO_INGRESO_NOMBRE: printf("ERROR: No ingreso nombre\n");break;
        case NO_INGRESO_TERMINO: printf("ERROR: No ingreso termino/s\n");break;
        case PARAMETROS_INVALIDOS: printf("ERROR: Faltan Parametros\n");break;
        case NO_EXISTE_ARCHIVO: printf("ERROR: El archivo no existe\n");break;
        case ABB_VACIO: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE); printf("No hay polinomios en memoria\n");break;
        case OK: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("OK\n");break;
        case CERRAR: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("\n************Hasta la proxima************\n");break;
        case BIENVENIDA: SetConsoleTextAttribute(hConsoleHandle, OriginalColors); printf("************Bienvenido al sistema de gestion de Polinomios*************\n");break;
        case INGRESO: SetConsoleTextAttribute(hConsoleHandle, OriginalColors); printf("\nIngrese comando: ");break;
        case GUARDADO: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("polinomio almacenado correctamente en ");break;
        case NOMBRE_ARCHIVO_INVALIDO:printf("ERROR: Nombre de archivo invalido, ingrese un nombre alfanumerico sin extension\n");break;
        case NO_GUARDADO: printf("Polinomio no guardado\n");break;
        case OPCION_INCORRECTA: printf("ERROR: Opcion incorrecta\n");
    }

    SetConsoleTextAttribute(hConsoleHandle, OriginalColors);
}

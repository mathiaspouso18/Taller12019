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
        case NOMBRE_INVALIDO: printf("ERROR: Nombre invalido");break;
        case NUMERO_INVALIDO: printf("ERROR: Numero invalido");break;
        case COMANDO_INVALIDO: printf("ERROR: Comando invalido");break;
        case YA_EXISTE: printf("ERROR: Ya existe polinomio con ese nombre");break;
        case NO_EXISTE_POLINOMIO: printf("ERROR: No existe polinomio con ese nombre");break;
        case NO_INGRESO_NOMBRE: printf("ERROR: No ingreso nombre");break;
        case NO_INGRESO_TERMINO: printf("ERROR: No ingreso termino/s");break;
        case PARAMETROS_INVALIDOS: printf("ERROR: Faltan Parametros");break;
        case ABB_VACIO: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE); printf("No hay polinomios en memoria");break;
        case OK: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("OK");break;
        case CERRAR: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("************Hasta la proxima************\n");break;
        case BIENVENIDA: SetConsoleTextAttribute(hConsoleHandle, OriginalColors); printf("************Bienvenido al sistema de gestion de Polinomios*************\n");break;
        case INGRESO: SetConsoleTextAttribute(hConsoleHandle, OriginalColors); printf("\nIngrese comando: ");break;
        case GUARDADO: SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN); printf("polinomio almacenado correctamente en ");break;
    }

    SetConsoleTextAttribute(hConsoleHandle, OriginalColors);
}

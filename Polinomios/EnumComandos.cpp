#include "EnumComandos.h"

EnumComandos ValidarComando(String s)
{
    EnumComandos ec = NADA;
    if(StrEq(s, "crear"))
        ec = CREAR;
    else if(StrEq(s, "sumar"))
        ec = SUMAR;
    else if(StrEq(s, "multiplicar"))
        ec = MULTIPLICAR;
    else if(StrEq(s, "evaluar"))
        ec = EVALUAR;
    else if(StrEq(s, "esraiz"))
        ec = ES_RAIZ;
    else if(StrEq(s, "mostrar"))
        ec = MOSTRAR;
    else if(StrEq(s, "guardar"))
        ec = GUARDAR;
    else if(StrEq(s, "recuperar"))
        ec = RECUPERAR;
    else if(StrEq(s, "salir"))
        ec = SALIR;

    return ec;
}

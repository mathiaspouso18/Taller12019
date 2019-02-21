#include "EnumComandos.h"

TipoMensaje ValidarComando(String s){
TipoMensaje temp = COMANDO_INVALIDO;

if (StrEq(s,"crear"))
    temp = OK;

return temp;
}

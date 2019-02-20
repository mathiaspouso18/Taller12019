
#include "EnumComandos.h"

EnumComandos Mapeo(String s)
{
    String aux = new char[MAX];
    aux[0] = 'C';
    aux[1] = 'R';
    aux[2] = 'E';
    aux[3] = 'A';
    aux[4] = 'R';
    aux[5] = '\0';
    if(StrEq(s, aux))
        return (CREAR);
}

TipoMensaje ValidarComando(String comando)
{
    TipoMensaje check = COMANDO_INVALIDO;
    EnumComandos comandoMapeado = Mapeo(comando);
    switch(comandoMapeado)
    {
        case CREAR:check = OK;
        break;
    }

}

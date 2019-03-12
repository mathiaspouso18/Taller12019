
#include "String.h"

void StrCrear (String & s){
    s = new char[1];
    s[0] = '\0';
}

void StrDestruir (String &s){
    delete [] s;
    s = NULL;
}

int StrLar (String s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void StrCop (String &s1,String s2){
    int i = 0;
    int largo = StrLar(s2) + 1;
    //delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void Scan (String &s){
    String aux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while ((c!= '\n' && i < MAX-1)){
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StrCop (s,aux);
    StrDestruir (aux);
}

void StrCon (String &s1,String s2)
{
     String aux;
     StrCrear(aux);
     StrCop(aux, s1);
     int largo = StrLar(s1) + StrLar(s2) + 1;
     if (largo > MAX)
     largo = MAX;

     delete [] s1;
     s1 = new char[largo];
     int i = 0;
     while (aux[i] != '\0')     {
         s1[i] = aux[i];
         i++;
     }
     int j = 0;
     while (s2[j] != '\0' && i < MAX-1){
         s1[i] = s2[j];
         i++;
         j++;
     }
     s1[i] = '\0';
     StrDestruir(aux);
}

void StrSwp (String &s1, String &s2){
    String aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void Print (String s){
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

Boolean StrEq(String s1, String s2)
{
	int i = 0;
	Boolean iguales = TRUE;

	while(iguales && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		if(s1[i] != s2[i])
			iguales = FALSE;
		i++;
	}

	if((s1[i] != '\0') || (s2[i] != '\0'))
		iguales = FALSE;

	return iguales;
}

int ConvertirCharANumero(String s)
{
	int cantItem = 0, contador = 0, resultado = 0, multiplicador = 1, i = 0;
	while (s[cantItem] != '\0')
	{
		cantItem++;
	}

	i = cantItem;
	for (contador = 0; contador < i; contador++)
	{
	    if(s[cantItem-1] != '-' && s[cantItem-1] != '+' && s[cantItem-1] != ' ')
        {
            resultado = resultado + (s[cantItem-1]-48) * multiplicador;
            multiplicador = multiplicador *10;
            cantItem--;
        }
	}

	return resultado;
}

Boolean EsValidoNombre(String s)
{
	int i = 0;
	Boolean es = TRUE;
	while(s[i] != '\0' && es)
	{
		if ((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'Z' && s[i] <= 'Z'))
			es = TRUE;
		else
            es = FALSE;

		i++;
	}

	return es;
}

Boolean EsValidoNombreArchivo(String s){
	Boolean es= FALSE, validonombre = FALSE, validoext = TRUE;
	int i = 0, j = 0;
	String s1, s2, ext;
	StrCrear(s1);
	StrCrear(s2);
	StrCrear(ext);
	ext[0] = '.';
	ext[1] = 't';
	ext[2] = 'x';
	ext[3] = 't';
	ext[4] = '\0';

	while(s[i] != '.' || s[i] == '\0')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	while(s[i] != '\0')
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	validonombre = EsValidoNombre(s1);
	i = 0;

	while(((s2[i] != '\0') || (ext[i] != '\0')) & validoext)
	{
		if(s2[i] == ext[i])
			validoext = TRUE;
		else
			validoext = FALSE;
		i++;
	}

	if(validonombre && validoext)
		es = TRUE;
	return es;
}

Boolean EsValidoNumero(String s)
{
	int i = 0;
	Boolean es = TRUE;
	while(s[i] != '\0' && es)
	{
		if(s[i]=='-' && i==0)
		{
			if(s[i+1] >= '0' && s[i+1] <= '9')
				es = TRUE;
			else
				es = FALSE;
		}
		else
        {
			if((s[i] >= '0' && s[i] <= '9'))
				es = TRUE;
			else
				es = FALSE;
		}
		i++;
	}

	return es;
}

Boolean EsMayor(String s1, String s2)
{
	Boolean es = FALSE, stop = FALSE;
	int i = 0;

	while(!stop && ((s1[i] != '\0') || (s2[i] != '\0'))){
		if(s1[i] < s2[i])
		{
			es = TRUE;
			stop = TRUE;
		}
		else
		{
			if(s1[i] > s2[i])
			{
				es = FALSE;
				stop = TRUE;
			}
		}
		i++;
	}
	return es;
}

void Guardar_String (String s, FILE * f)
{
	int i=0;
    while (s[i] != '\0')
    {
		fwrite (&s[i], sizeof(char), 1, f);
		i++;
    }
    // escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}

void LowerCase(String &s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i]<= 'Z')
			s[i] = s[i] + 32;
		i++;
	}
}

void Levantar_String (String &s, String nomArch)
{
     FILE *f = fopen (nomArch, "rb");
	 int i=0;
	 String aux;
	 aux = new char[MAX];
	 fread (&aux[i], sizeof(char), 1, f);
	 while (!feof(f) && (aux[i] != '\0'))
	 {
         i++;
         fread (&aux[i], sizeof(char), 1, f);
	 }
	 aux[i] = '\0';
	 StrCop (s, aux);
	 delete [] aux;
}

void IntToString(String &s, int num)
{
    String aux = new char[MAX];

    int x=10, cant=1, i;
    char c;
    while (num >= x ){
        x=x*10;
        cant++;
    }
    int y = x/10;

    for(i=0;i<cant;i++){
        c =((num%x)/y)+48;
        aux[i]=c;
        x=x/10;
        y=y/10;
    }
    aux[i] = '\0';
    StrCop (s,aux);
    StrDestruir (aux);
}

Boolean ExisteArchivo(String s)
{
    FILE * f = fopen(s, "rb");
    Boolean existe = FALSE;

    if(f != NULL)
    {
        fclose(f);
        existe = TRUE;
    }
    return existe;
}

Boolean EsCaracterValido(char c)
{
    Boolean es = FALSE;

    //Comparo contra la tabla ASCII para que acepte todo los valores entrantes, distinto a Espacio (32)
    if(c >= 33 && c <= 126)
            es = TRUE;
    else
        es = FALSE;

    return es;
}

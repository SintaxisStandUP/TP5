#include <stdio.h>
#include "scanner.h"
#include "parser.h"
//#include "symbol.h"
char *diccionario[200];
int encontrado = 0,i=0;
int iProx=0; 


int buscar(char *id){
	i=0;
	while (i<iProx){
		if (!strcmp(id,diccionario[i])) //La función devuelve 0 cuando son iguales.
			return 1;
		i++;
	}	
	return 0; //si devuelve 1 se encontro el id, si devuelve 0 no
}

void agregar (char *id){
	diccionario[iProx]=id;
	iProx++;
}

char* declararTemporal(int nro){
	char str[8];//Temp#XX 8carac.(\0)
	sprintf(str, "Temp#%d", nro);
	//char* buf = strdup(str);
	return strdup(str);
}

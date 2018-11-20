#include <stdio.h>
#include "scanner.h"
#include "parser.h"
#include "symbol.h"

int buscar(char *id){
	while (i<iProx){
		if (id==diccionario[i])
			encontrado=1;
		i++;
	}	
	return encontrado; //si devuelve 1 se encontro el id, si devuelve 0 no
}

void agregar (char *id){
	diccionario[iProx]=id;
	iProx++;
}



#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "parser.h"
#include "semantic.h"
#include "symbol.h"
int nroDeTemporal=1;
void inicio(){
      printf("Load rtlib, \n");
}
char* proxTemp(){return "hol";}

void operacion(char *idEntrada1,int operando, char *idEntrada2){
	char *idSalida = declararTemporal(nroDeTemporal);
	declarar(idSalida);
	nroDeTemporal++;
	if (buscar(idEntrada1) && buscar(idEntrada2)){
		switch(operando){
		case 0:
			printf("INV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
			break;

		case '+':
			printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
			break;
		case '-':
			printf("SUBS %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
			break;
		case '*':
			printf("MULT %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
			break;
		case '/':
			printf("DIV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
			break;
		}
		free(idEntrada1);
		idEntrada1 = strdup(idSalida);
	}
	else{
		declararError(idEntrada1, idEntrada2);
	}
}


void declarar (char *id){
	if (!buscar(id)){ //Si no se encuentra en el diccionario es exito
		printf ("Declare %s , Integer\n",id);
		agregar(id);
	}
	else
	{	yySEM++;
		sprintf(bufferEr,"Error semántico: identificador %s ya declarado",id);
		yyerror(bufferEr);
		
	}
}
 

void declararError(char* id1, char* id2){
	if(!buscar(id1)){
		yySEM++;
		sprintf(bufferEr,"Error semántico: identificador %s ya declarado",id1);
		yyerror(bufferEr);
		}
	else{
		yySEM++;
		sprintf(bufferEr,"Error semántico: identificador %s ya declarado",id2);
		yyerror(bufferEr);
		}
}
void asignar(char *idEntrada, char *idSalida){
      printf("Store %s, %s \n", idSalida, idEntrada);
}
 
void leer(char *id){
	if(!buscar(id)){
		yySEM++;
		sprintf(bufferEr,"Error semántico: identificador %s no declarado",id);
		yyerror(bufferEr);
		}
	else{
      	printf("Read %s, Integer\n",id);
	}
}
 
void escribir(char *id){
	if(!buscar(id)){
		yySEM++;
		sprintf(bufferEr,"Error semántico: identificador %s no declarado",id);
		yyerror(bufferEr);
		}
	else{
      		printf("Write %s, Integer\n",id);
	}
}
 
void fin(){
      printf ("Stop ,\n");
}












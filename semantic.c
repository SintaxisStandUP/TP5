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
		
		default:
			printf("no salio capo\n");
	}
		free(idEntrada1);
		idEntrada1 = strdup(idSalida);
//	return idSalida;
}
/*
void inversion(char  *idEntrada1){
	char *idSalida = declararTemporal(nroDeTemporal);
	declarar(idSalida);
	nroDeTemporal++;
	printf("INV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
}
*/

void declarar (char *id){
	if (!buscar(id)){ //Si no se encuentra en el diccionario es exito
		printf ("Declare %s , Integer\n",id);
		agregar(id);
	}
	else
	{;}
	//Faltaria agregarle el error. Va en el parser?
}
 

 
void asignar(char *idEntrada, char *idSalida){
      printf("Store %s, %s \n", idSalida, idEntrada);
}
 
void leer(char *id){
      printf("Read %s, Integer\n",id);
}
 
void escribir(char *id){
      printf("Write %s, Integer\n",id);
}
 
void fin(){
      printf ("Stop, \n");
}











char* sumar(char *idEntrada1,int algo, char *idEntrada2){
      char *idSalida = declararTemporal(nroDeTemporal);
	printf("aca esta el temp: %s\n",idSalida);
     // idSalida = proxTemp();
      printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return "hola";
}

char* restar(char *idEntrada1, char *idEntrada2){
      char *idSalida;
      idSalida = proxTemp();
      printf("SUBS %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return idSalida;
}
 
char* multiplicar(char *idEntrada1, char *idEntrada2){
      char *idSalida;
      idSalida = proxTemp();
      printf("MULT %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return idSalida;
}
 
char* dividir(char *idEntrada1, char *idEntrada2){
      char *idSalida;
      idSalida = proxTemp();
      printf("DIV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return idSalida;
}


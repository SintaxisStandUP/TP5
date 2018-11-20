#include <stdio.h>
#include "scanner.h"
#include "parser.h"
#include "semantic.h"
#include "symbol.h" //esta bien incluirla? para poder usar el buscar y agregar
void inicio(){
      printf("Load rtlib, \n");
}
 
char* sumar(char *idEntrada1, char *idEntrada2){
      char *idSalida;
      idSalida = proxTemp();
      printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return idSalida;
}

char* declarar (char *id){
	if (buscar(id)==0){ //Si no se encuentra en el diccionario es exito
		printf ("Declare %s , Integer");
		agregar(id);
	}
	//Faltaria agregarle el error. Va en el parser?
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
 
char* asignar(char *idEntrada, char *idSalida){
      printf("Store %s, %s \n", idEntrada, idSalida);
      return idSalida;
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


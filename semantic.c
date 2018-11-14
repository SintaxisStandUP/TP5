#include <stdio.h>
#include "scanner.h"
#include "parser.h"
#include "semantic.h"
void inicio(){
      printf("Load rtlib, \n");
}
 
char* sumar(char *idEntrada1, char *idEntrada2){
      char *idSalida;
      idSalida = proxTemp();
      printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
      return idSalida;
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

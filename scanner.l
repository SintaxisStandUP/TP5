%top{
#include <stdio.h>
#include "parser.h"
#include <string.h>
char buffer[100];
}
%option header-file="scanner.h"
%option outfile="scanner.c"
%option yylineno
%option noinput
%option nounput

L [[:alpha:]]
D [0-9]
LD [[:alnum:]]
S [[:space:]]

O [[:punct:]]{-}[,.()+*/-]
%%
"//".*|" "|\t|\n    	; 
programa		return PROG;
variables		return VAR;
codigo			return COD;
fin			return FIN;
leer			return LEER;
escribir		return ESC;
definir			return DEF;
"+"			return '+';
"-"			return '-';
"*"			return '*';
"/"			return '/';
"<-"			return ASIG;
"("			return '(';
")"			return ')';
","			return ',';
"."			return '.';
{L}{LD}*		{yylval = strdup(yytext); return ID;}
{D}+			{yylval = strdup(yytext); return CTE;}
{D}+{LD}*		{	yylexerrs++;
				sprintf(buffer,"Error lexico: constante invalida: %s",yytext);
			 	yyerror(buffer);
				}
{L}+({LD}*{O}*)+	{	yylexerrs++; 
				sprintf(buffer,"Error lexico: identificador invalido: %s",yytext);
			 	yyerror(buffer);}//{L}+{O}+({LD}*{O}*)*
{O}+({LD}*{O}*)*	{	yylexerrs++;
				sprintf(buffer,"Error lexico: cadena desconocida: %s",yytext);
			 	yyerror(buffer);}//modificado, antes era {O}+
%%


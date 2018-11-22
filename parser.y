%code top{
#include <stdio.h>
#include "scanner.h"
#include "semantic.h"
#include <string.h>
char* linea;
}

%code provides{
	void yyerror(const char *s);
	int yylexerrs;
	int yynerrs;
}

%defines "parser.h"
%output "parser.c"
%token ID CTE PROG VAR COD FIN LEER ESC DEF ASIG
%left '-' '+'
%left '*' '/'

%precedence NEG

%define api.value.type {char *}
%define parse.error verbose

%%
estructura : PROG {inicio();} VAR definicion COD sentencias FIN {if (yynerrs || yylexerrs) YYABORT; else YYACCEPT;}

definicion : definicion DEF variables
		|DEF variables
		| error  '.';

variables : ID '.' {declarar(yyval);}
		
sentencias : sentencias sentencia | sentencia;

sentencia: lectura | escritura | asignacion | error '.';

lectura : LEER '(' listaIdentificadores ')' '.';
escritura : ESC '(' listaExpresiones ')' '.' {printf ("escribir \n");};
asignacion : ID ASIG expresion '.' {asignar($1,$3);};

listaIdentificadores : listaIdentificadores ',' ID {leer($3);}| ID{leer(yyval);} | error  '.';
listaExpresiones : listaExpresiones ',' expresion | expresion | error  '.';


expresion: 	expresion '+' expresion {operacion($1,'+',$3);}
		|expresion '-' expresion{operacion($1,'-',$3);} 
		|expresion '*' expresion {operacion($1,'*',$3);}
		|expresion '/' expresion {operacion($1,'/',$3);}
		|ID 
		|CTE 
		|'(' expresion ')' {printf ("parentesis \n");}
		| '-' expresion %prec NEG{operacion($2,0,"");$$=$2;}//el 0 es por la inversion
		;


%%


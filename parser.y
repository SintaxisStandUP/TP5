%code top{
#include <stdio.h>
#include "scanner.h"
#include "semantic.h"
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
estructura : PROG VAR definicion COD sentencias FIN {if (yynerrs || yylexerrs) YYABORT; else YYACCEPT;}

definicion : definicion DEF variables
		|DEF variables
		| error  '.';

variables : ID '.' {printf ("definir %s \n", yyval);}
		
sentencias : sentencias sentencia | sentencia;

sentencia: lectura | escritura | asignacion | error '.';

lectura : LEER '(' listaIdentificadores ')' '.' {printf ("leer \n");};
escritura : ESC '(' listaExpresiones ')' '.' {printf ("escribir \n");};
asignacion : ID ASIG expresion '.' {printf ("asignacion \n");};

listaIdentificadores : listaIdentificadores ',' ID | ID | error  '.';
listaExpresiones : listaExpresiones ',' expresion | expresion | error  '.';


expresion: 	expresion '+' expresion {sumar($1,'+',$3);}
		|expresion '-' expresion{printf ("resta \n");} 
		|expresion '*' expresion {printf("multiplicacion\n");}
		|expresion '/' expresion {printf("division\n");}
		|ID 
		|CTE 
		|'(' expresion ')' {printf ("parentesis \n");}
		| '-' expresion %prec NEG{printf ("inversion \n");}
		;


%%


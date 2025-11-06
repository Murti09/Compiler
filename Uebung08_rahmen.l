%{
#include <stdio.h>
#include <stdlib.h>
%}

ziffer [0-9]
letter [a-zA-Z]
sign [+-]
zeichen [_]

%%
while { printf("Schluesselwort gefunden! Schluesselwort=%s \n",yytext); }
{letter}({letter}|{ziffer}|{zeichen})* { printf("Bezeichner gefunden! Name=%s \n",yytext); }
{sign}?{ziffer}+ { printf("Ganzzahl gefunden! Zahlenwert=%s \n",yytext); }
{sign}?{ziffer}+([.,]){ziffer}+ { printf("Gleitkommazahl gefunden! Zahlenwert=%s \n",yytext); }
%%

yywrap()
{
 return 0;
};

void main()
{
 do { yylex (); } 
 while (! feof(stdin));
}

%{
#include <stdio.h>
#include <stdlib.h>

int binaerZuDezimal(const char* text)
{
    int dezimal = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];
        if (c == 'i' || c == 'I')
        {
            dezimal = dezimal * 2 + 1;
        }
        else if (c == 'o' || c == 'O')
        {
            dezimal = dezimal * 2 + 0;
        }
    }
    return dezimal;
}
%}

ziffer [0-9]
letter [i,I,o,O]

%%
{ziffer}+ { printf("Dezimalzahl gefunden! Zahlenwert=%s \n",yytext); }
{letter}+ { printf("Binaerzahl gefunden! Binaerwert=%s Dezimalwert=%d \n",yytext, binaerZuDezimal(yytext)); }
%%

int yywrap()
{
 return 0;
};

void main()
{
 do { yylex (); } 
 while (! feof(stdin));
}

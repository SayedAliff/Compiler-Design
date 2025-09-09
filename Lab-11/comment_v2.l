%{
#include <stdio.h>
%}

%%

^"//"            { printf("This is a single line comment\n"); }
^"/*"[^*]*|[*]*"*/"  { printf("This is a Multiline Comment\n"); }
\n               ;

%%

int yywrap(void) { return 1; }
int main()
{
    yylex();
}
%{
    /* USE OF REJECT STATEMENT */
    #include <stdio.h>
    int yywrap(void) { return 1; }
%}

%%

[a-z]+ {
    printf("\ncontains only lowercase letters = ");
    ECHO;
}

[a-zA-Z]+ {
    printf("\ncontains both uppercase and lowercase letters = ");
    ECHO;
    REJECT;
}

. {
    printf("\ncontains mixed letters = ");
    ECHO;
}

%%

int main()
{
    yylex();
}
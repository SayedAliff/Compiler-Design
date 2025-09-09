%{
#include <stdio.h>
int count = 0;
%}

%%

[A-Z] { printf("%s capital letter\n", yytext); count++; }
.     { printf("%s not a capital letter\n", yytext); }
\n    { return 0; }

%%

int yywrap(void) { return 1; }
int main()
{
    FILE *fp;
    char filename[50];
    printf("Enter the filename: \n");
    scanf("%s",filename);
    fp = fopen(filename,"r");
    if (!fp) {
        printf("File not found!\n");
        return 1;
    }
    yyin = fp;
    yylex();
    fclose(fp);
    printf("\nNumber of Capital letters in the given input - %d\n", count);
    return 0;
}
%{
    /* Inclusive start condition */
    #include <stdio.h>
    int yywrap(void) { return 1; }
%}

%s SM SMBG

%%

#      BEGIN(SM);
##     BEGIN(SMBG);

[0-9]+ {
    printf("Contains only digits\n");
}

<SMBG>[A-Z]+ {
    printf("Contains uppercase letters\n");
}

<SM>. {
    printf("Exiting from # start condition\n");
    BEGIN(INITIAL);
}

<SM,SMBG>[a-z]+ {
    printf("Contains lowercase letters\n");
}

<SMBG>.+ {
    printf("Exiting from ## start condition\n");
    BEGIN(INITIAL);
}

.+ {
    printf("No action executed\n");
}

%%

int main()
{
    printf("Enter # when expecting digits or lowercase letters\n");
    printf("Enter ## when expecting only lowercase and uppercase letters\n");
    yylex();
}
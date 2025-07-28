#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* types[] = {"int", "float", "double", "char", "void"};
int isType(char* w) {
    for(int i=0; i<5; i++) if(strcmp(w, types[i])==0) return 1;
    return 0;
}

int main() {
    FILE* f = fopen("input.txt", "r");
    char line[256], w1[32], w2[32];
    while(fgets(line, 256, f)) {
        sscanf(line, "%31s %31s", w1, w2);
        if(isType(w1) && strchr(line, '(') && strchr(line, ')') && strchr(line, ';'))
            printf("Function Declaration: %s", line);
        else if(isType(w1) && strchr(line, '(') && strchr(line, ')') && strchr(line, '{'))
            printf("Function Definition: %s", line);
        else if(isType(w1) && isalpha(w2[0]) && strchr(line, ';'))
            printf("Variable Declaration: %s", line);
    }
    fclose(f);
    return 0;
}
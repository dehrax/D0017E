#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lab2_funcs.h"
#define MAX_BUFFER 255

int processLine(const char *line){
    char input[MAX_BUFFER];

    strcpy(input, line);//We don't want that const
    if(!strcmp(input, "quit")){
        puts("\nOkay, bye!");
        return 0;
    }

    char* args[10];
    int argc = 0;

    //Changes the spaces to null character and adds the beginning of a new string to 
    args[argc++] = input;

    char* p = input;
    while(*p != '\0'){
        if(isspace(*p)){
            *p = '\0';
            args[argc++] = p + 1;
        }
        p++;
    }

    if(!strcmp(args[0], "hello")){
        puts("Hi on you too!");
    }

    return 1;
}; 

int readLine(void){
    char input[MAX_BUFFER];

    do{
        printf(">>");
        fgets(input, MAX_BUFFER, stdin);
    }while(processLine(input));

    return 0;
}

int main(int argc, char *argv[]) {
    readLine();
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lab2_funcs.h"
#include "operations.h"
#include "lab2.h"
#define MAX_BUFFER 255

matlab_var_t vars[] = {
    {'a', 0.0},
    {'b', 0.0},
    {'c', 0.0},
    {'r', 0.0},
    {'x', 0.0},
    {'y', 0.0}
};


matlab_arr_t arrs[] = {
    {'A'},
    {'B'},
    {'C'},
    {'R'},
    {'X'},
    {'Y'}
};

int processLine(const char *line){
    char input[MAX_BUFFER];

    strcpy(input, line);//We don't want that const

    char* args[10];
    int argc = 0;

    //Changes the spaces to null character and adds the beginning of a new string to 
    args[argc++] = input;

    char* p = input;
    while(*p != '\0'){
        if(*p == '='){
            inlineArithmetic(line);
            return 1;
        } else if(isspace(*p)){
            *p = '\0';
            args[argc++] = p + 1;
        }
        p++;
    }

    if(!strcmp(args[0], "quit")){
        puts("Okay, goodbye!");
        return 0;
    } else if(!strcmp(args[0], "exit")){
        puts("Okay, goodbye!");
        return 0;
    } else if(!strcmp(args[0], "show")){
        //Takes first char in string
        show(args[1][0]);
    } else if(!strcmp(args[0], "vars")){
        show_vars();
    } else if(!strcmp(args[0], "exportMAT")){
        exportMAT(args[1][0], args[2]);
    } else if(!strcmp(args[0], "clear")){
        //Takes first char in string
        clear(args[1][0]);
    } else if (!strcmp(args[0], "set")){
        double a = 0;
        sscanf(args[2], "%lf", &a);
        set(args[1][0], a);
    } else if (!strcmp(args[0], "add")){
        vecOps(find_arr('A'), find_arr('B'), add, find_arr('C'));
    } else if (!strcmp(args[0], "array")){
        double a = 0, b = 0;
        sscanf(args[2], "%lf", &a);
        sscanf(args[3], "%lf", &b);
        array(args[1][0], a, b);
    } else if (!strcmp(args[0], "help")){
        printhelp();
    }else if (!strcmp(args[0], "showFile")){
        showCSV(args[1]);
    }else if (!strcmp(args[0], "importCSV")){
        importCSV(args[1][0], args[2]);
    }else if (!strcmp(args[0], "exportCSV")){
        exportCSV(args[1][0], args[2]);
    }else{
        puts("Wow there, buddy! Can't find that command!");
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

int initVars(){
    for(int i = 0; i < ARRAY_LEN; i++){
        arrs[0].v[i]=0;
        arrs[1].v[i]=0;
        arrs[2].v[i]=0;
        arrs[3].v[i]=0;
        arrs[4].v[i]=0;
        arrs[5].v[i]=0;
    }
    return 0;
}

int inlineArithmetic(const char* input){
    char result = input[0];
    char A = input[2];
    char B = input[4];
    char operation = input[3];

    calc(result, A, B, operation);
    return 0;
}

int main(int argc, char *argv[]) {
    initVars();
    readLine();
    return 0;
}
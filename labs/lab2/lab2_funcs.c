#include <stdio.h>
#include "lab2.h"

void printhelp(void);

matlab_var_t *find_var(char var){

    //Loop through amount of variables and check the name
    for(int i = 0; i<6;i++){
        if(vars[i].n == var)
            return &vars[i];
    }
    return NULL;
}

int show(char name){
    matlab_var_t* var = find_var(name);
    if(!var){
        printf("Can't find variable called '%c'\n", name);
    } else{
        printf("%c = %g\n", name, var->v);
        return 1;
    }

    return 0;
}
#include <stdio.h>
#include "lab2.h"
#include "operations.h"
#include <ctype.h>

void printhelp(void);

matlab_var_t *find_var(char var){

    //Loop through amount of variables and check the name
    for(int i = 0; i<6;i++){
        if(vars[i].n == var)
            return &vars[i];
    }
    return NULL;
}

matlab_arr_t *find_arr(char var){
    for(int i = 0; i<6;i++){
        if(arrs[i].n == var)
            return &arrs[i];
    }
    return NULL;
}

int array(char name, double start, double stop){
    matlab_arr_t *array = find_arr(name);
    if(!array){
        printf("Could not find variable called '%c'", name);
        return 1;
    }
    
    double step = (stop - start)/ (ARRAY_LEN-1);

    for(int i = 0; i < ARRAY_LEN; i++){
        array->v[i] = start + i*step;
    }

    return 0;
}

int show(char name){
    if(isupper(name)){
        matlab_arr_t* var = find_arr(name);
        if(!var){
            printf("Can't find variable called '%c'\n", name);
        } else{
            printf("%c =\n", name);
            for(int i = 0; i < ARRAY_LEN; i++){
                printf("[%i]: %g\n", i, var->v[i]);
            }
            return 0;
        }
    }else{
        matlab_var_t* var = find_var(name);
        if(!var){
            printf("Can't find variable called '%c'\n", name);
        } else{
            printf("%c = %g\n", name, var->v);
            return 0;
        }
    }

    return 1;
}

int clear(char name){
    matlab_var_t* var = find_var(name);
    if(!var){
        printf("Can't find variable called '%c'\n", name);
    } else{
        var->v = 0;
        show(name);
        return 0;
    }

    return 1;
}

int set(char name, double value){
    matlab_var_t* var = find_var(name);
    double double_val = 0;
    if(!var){
        printf("Can't find variable called '%c'\n", name);
    } else{
        sscanf(value, "%lf", &double_val);
        var->v = double_val;
        show(name);
        return 0;
    }

    return 1;

}

int calc(char r, char x, char y, char op){
    double a = 0, b = 0, c = 0;
    matlab_arr_t* A, B, C;
    double (*func_ptr)(double, double);
    int isMatrix = 0;

    //Fetch variables
    if(isupper(r)){
        isMatrix = 1;
    }

    //TODO: Handle input and variable assigment. What to do when multiplying vector with scalar?

    //Decide operation and save that operation in the function pointer
    switch(op){
        case '/':
            func_ptr = divide;
            break;
        case '*':
            func_ptr = multiply;
            break;
        case '+':
            func_ptr = add;
            break;
        case '-':
            func_ptr = subtract;
            break;
    }

    isMatrix ? vecOps(A, B, func_ptr, C) : set(r, func_ptr(a,b));
    
}
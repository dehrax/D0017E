#include "operations.h"

double add(double a, double b){
    return a + b;
}

double subtract(double a, double b){
    return a - b;
}

double divide(double a, double b){
    return a/b;
}

double multiply(double a, double b){
    return a*b;
}

int vectorElOperation(matlab_arr_t *var, double (*func)(double), matlab_arr_t* result){
    for(int i = 0; i<ARRAY_LEN; i++){
        result->v[i] = func(var->v[i]);
    }
    return 0;
}

int vectorsElOperation(matlab_arr_t* var1, matlab_arr_t* var2, double (*func)(double, double), matlab_arr_t* result){
    for(int i = 0; i < ARRAY_LEN; i++){
        result->v[i] = func(var1->v[i], var2->v[i]);
    }

    return 0;
}
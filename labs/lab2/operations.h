#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <math.h>
#include "lab2.h"

double add(double a, double b);
double subtract(double a, double b);
double divide(double a, double b);
double multiply(double a, double b);


//Pass function as parameter to operate on single element
int vectorElOperation(matlab_arr_t* var, double (*func)(double), matlab_arr_t* result);

//Element-wise operation between two vectord
int vectorsElOperation(matlab_arr_t* var1, matlab_arr_t* var2, double (*func)(double, double), matlab_arr_t* result);



#endif
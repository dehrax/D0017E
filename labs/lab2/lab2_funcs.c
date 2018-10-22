#include <stdio.h>
#include "lab2.h"
#include "operations.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    We continue to monitor restores which are taking longer than anticipated. We estimate they will be caught up in an hour and a half.
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
                printf("[%i]: %g\n", i+1, var->v[i]);
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
    if(!isupper(name)){
        matlab_var_t* var = find_var(name);
        if(!var){
            printf("Can't find variable called '%c'\n", name);
        } else{
            var->v = 0;
            show(name);
            return 0;
        }
    } else{
        matlab_arr_t* arr = find_arr(name);
        if(!arr){
            printf("Can't find variable called '%c'\n", name);
        } else{
            for(int i = 0; i < ARRAY_LEN; i++){
                arr->v[i] = 0;
            }
            show(name);
            return 0;
        }
    }

    return 1;
}

int set(char name, double value){
    matlab_var_t* var = find_var(name);
    if(!var){
        printf("Can't find variable called '%c'\n", name);
    } else{
        var->v = value;
        show(name);
        return 0;
    }

    return 1;

}

int showCSV(const char *filename){
    FILE *inputFile = fopen(filename, "r");

    char content[ARRAY_LEN];
    if(!inputFile)
     {
         printf("Thou has failed to deliver the foremost correct file and this shall not pass!\n");
         return 1;
     }

    while(fgets(content, ARRAY_LEN, inputFile))
    {
        printf("%s", content);
    }
    fclose(inputFile);
    printf("\n"); 
    
    return 0;
}

int importCSV(char var, const char *filename)
{
    FILE *inputFile = fopen(filename, "r");
    char content[ARRAY_LEN];
    matlab_arr_t *array = find_arr(var);
    double val;
    if(!array)
    {
        printf("Could not find array called '%c'\n", var);
        fclose(inputFile);
        return 1;
    }
    else if(!inputFile)
    {
         printf("Thou has failed to deliver the foremost correct file and this shall not pass!\n");
         return 1;
    }
     
    for(int i = 0; i < ARRAY_LEN; i++){
        fgets(content, ARRAY_LEN, inputFile);
        
        if (sscanf(content, "%lf", &val) == 1) //Without this the values get shifted with 48 since content is stored as ASCII 
        {
            array->v[i]=val;
        }
    }
    fclose(inputFile);
    return 0; 
}

int exportCSV(char var, const char *filename)
{
    FILE *outputFile = fopen(filename, "w");
    matlab_arr_t *array = find_arr(var);

    if(!array)
    {
        printf("Could not find array called '%c'\n", var);
        fclose(outputFile); 
        return 1;
    }
    for(int i = 0; i < ARRAY_LEN; i++){
        fprintf(outputFile, "%f\n", array->v[i]);
    }

    fclose(outputFile);
    return 0;

}

int show_vars(){
    for(int i = 0; i < 6; i++){
        printf("%c = %g\n", vars[i].n, vars[i].v);
    }
    return 0;
}

int calc(char r, char x, char y, char op){
    double a = 0, b = 0;
    matlab_arr_t *A = NULL, *B = NULL, *C = NULL;
    //Function pointer to define the operation to be used.
    double (*func_ptr)(double, double);
    int isMatrix = 0;

    //Fetch variables
    if(isupper(r) && isupper(x) && isupper(y)){
        isMatrix = 1;
        A = find_arr(x);
        B = find_arr(y);
        C = find_arr(r);
    } else if(!(isupper(r) && isupper(x) && isupper(y))){
        a = find_var(x)->v;
        b = find_var(y)->v;
    } else{
        puts("Please do not mix scalars and vectors! My brain can't handle it!");
        return 1;
    }

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

    isMatrix ? vectorsElOperation(A, B, func_ptr, C) : set(r, func_ptr(a,b));

    return 0;
}

int debounce(char R, char I)
{
    matlab_arr_t *resultArray = find_arr(R);
    matlab_arr_t *inputArray = find_arr(I);

    int nFollowingLow = 0, startLowIndex = 0, endLowIndex = 0;
    bool previousLow = false, pressFound = false;

    if(!resultArray)
    {
        printf("Could not find array called '%c'\n", R);
        return 1;
    }
    else if(!inputArray)
    {
        printf("Could not find array called '%c'\n", I);
        return 1;
    }

/* The analogue signal is sampled at 50Hz  with the duration of 1 second
    1/50=0,02 means every point of data equals 0,02 seconds or 20ms
    If the the transition is shorter than 200ms it should be ignored, if its greater than 200ms it should be registered
        200/20=10, meaning there hs to be at least 10 following points that have a value < 0.3V which is the limit.
*/

    for (int i = 0; i < ARRAY_LEN; i++)
    {
        double inputElement = inputArray->v[i];

        if (inputElement < 0.3)
        {
            if (nFollowingLow == 0 && pressFound == false)
            {
                startLowIndex = i;
            }
            if (nFollowingLow  >= 10 && previousLow == true && pressFound == false)
            {
                endLowIndex = i;
            }
    
            nFollowingLow++;
            previousLow = true;

        }
        else if (inputElement >= 3)
        {
            if (nFollowingLow < 10 && pressFound == false)
            {
                startLowIndex = i;
            }
            if (nFollowingLow >= 10)
            {
                endLowIndex = i-1;
                pressFound = true;
            }

            nFollowingLow = 0;
            previousLow = false;
        }
    }
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        if (i >= startLowIndex && i <= endLowIndex)
        {
            resultArray->v[i] = 0;
        }
        else
        {
            resultArray->v[i] = 3.30;
        }
    }

    return 0;

}

int printhelp(void){

    char help_message[] =   "Available commands:\n"
                            "\thelp: shows this message \n"
                            "\tset <var> <value>: Set variable <var> to value <value>, e.g \"set a 3.14\" \n"
                            "\tsin <res> <var>: Calculates the sin values of <var> and stores in <res> \n"
                            "\tshow <var>: Shows a scalar or array variable \n"
                            "\tshowFile <filename>: Shows the file <filename> \n"
                            "\tdeleteFile <filename>: Deletes the file <filename> \n"
                            "\timportCSV <var> <filename>: Imports variables from the CSV file <filename> and stores in array <var> \n"
                            "\texportCSV <var> <filename>: Saves a  variable <var> into the CSV file <filename> \n"
                            "\texportMAT <filename>: Saves a variable into the Matlab file <filename> \n"
                            "\texportJSON <filename>: Saves a variable into the JSON file <filename> \n"
                            "\texportXML <filename>: Saves a variable into the XML file <filename> \n"
                            "\tquit: exit this application \n"
                            "\texit: exit this application \n"
                            "\texit x: exit this application with return code x \n";             

    printf("%s", help_message); 
    return 0;
}

int event(matlab_arr_t* output, matlab_arr_t* input){
    double threshold = 0.5;
    int sampleLength = 10;

    for(int i = 0; i<ARRAY_LEN; i++ ){
        if(input->v[i] >= threshold){
            int j = 0;
            int end = 0;

            while(input->v[i+j] >= threshold || i+j >= ARRAY_LEN){
                output->v[i+j] = input->v[i+j];
                j++;
            }
            end = j;

            //Reset if sample is shorter than 10
            if(j < sampleLength){
                for(;j != 0; --j){
                    output->v[i+j-1] = 0; //-1 to get proper index
                }
            } else{
                printf("Event start detected at @%i\n", i);
                printf("Event end detected at @%i\n", i+j);
                
            }

            //We have handled these numbers now
            i = i+end;
            
        } else{
            output->v[i] = 0;
        }
    }

    return 0;
}

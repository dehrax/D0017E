#include <stdio.h>
#include "lab2.h"
#include "operations.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


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
    double val; //Variable called val since thats what i wanted to do when my values were shifted with 48

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

    isMatrix ? vecOps(A, B, func_ptr, C) : set(r, func_ptr(a,b));

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

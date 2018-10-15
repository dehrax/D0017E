#include <stdio.h>
#include "lab2.h"
#include <ctype.h>



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

int set(char name, char* value){
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


int printhelp(void)
{

    char help_message[] =   "Available commands:\n"
                            "\thelp: shows this message \n"
                            "\tset <var> <value>: Set variable <var> to value <value>, e.g \"set a 3.14\" \n"
                            "\tsin <res> <var>: Calculates the sin values of <var> and stores in <res> \n"
                            "\tshow <var>: Shows a scalar or array variable \n"
                            "\tshowFile <filename>: Shows the file <filename> \n"
                            "\tdeleteFile <filename>: Deletes the file <filename> \n"
                            "\timportCSV <var> <filename>: Imports variables from the CSV file <filename> and stores in array <var> \n"
                            "\texportCSV <filename>: Saves a  variable into the CSV file <filename> \n"
                            "\texportMAT <filename>: Saves a variable into the Matlab file <filename> \n"
                            "\texportJSON <filename>: Saves a variable into the JSON file <filename> \n"
                            "\texportXML <filename>: Saves a variable into the XML file <filename> \n"
                            "\tquit: exit this application \n"
                            "\texit: exit this application \n"
                            "\texit x: exit this application with return code x \n";
                            

    printf("%s", help_message);


    
    return 0;
}
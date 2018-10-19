#include <stdint.h>
#include <stdio.h>
#include "lab2.h"

int exportMAT(char var, const char* filename){
    
    FILE* file_ptr = fopen(filename, "wb");

    if(!file_ptr){
        puts("Whoops, can't read that file!");
        return 1;
    }

    matlab_arr_t* arr = find_arr(var);
    if(!arr){
        puts("Can't find correct variable");
        fclose(file_ptr);
        return 2;
    }


    Fmatrix header = {0000, ARRAY_LEN, 1, 0, 1};

    fwrite(&header, sizeof(Fmatrix), 1, file_ptr);

    fwrite(&var, sizeof(char), 1, file_ptr);

    fwrite(arr->v, sizeof(double), ARRAY_LEN, file_ptr);

    fclose(file_ptr);
 
    return 0;

}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 255

typedef struct{
    double width;
    double height;
    unsigned int size;
}paper;

int getInput(int value){
    bool invalidInput = false;
    char input[MAX_LENGTH];
    // char *value[MAX_LENGTH];

    int length;
        //Reset in case of second try
        invalidInput = false;

        printf("Which size do you want to calculate?\nA");

        fgets(input, MAX_LENGTH, stdin);
        
        
        //Check input length
        length = strlen(input);
        // printf("%i\n", length);

        //Check for trailing zeroes
        if(input[0] == '0' && length > 2){
            puts("Trailing zeros forbidden. 404 not found. 502 bad gateway.");
            exit(404);
        }

        if(length > 5){
            puts("You cannot enter more than 4 numeric characters! Maximum size is 1000, asshole.");
            invalidInput = true;
            exit(1);
        
        } else{
            //-1 for null character
            for(int i = 0; i < length-1; i++){
                char c = input[i];

                //Check if numeric characters
                if(!( 0x30 <= c && c <= 0x39)){
                    puts("Must be numeric characters only, please!");
                    invalidInput = true;
                    exit(2);
                    break;
                }
            }
        }

    //Convert to int
    sscanf(input, "%i", &value);

    if(value > 1000){
        puts("Maximum allowed size A1000");
        exit(3);
    }

    return value;
}

paper changeSize(int new_size){
    //Initiate as an A4
    paper aX = {210, 297, 4};

    if(new_size == 4){
        return aX;
    } else if(new_size < 4){
        
        int len = new_size - 4;
        for(int i = len ;i < 0 ;i++){
            paper temp = aX;
            aX.height = temp.width*2;
            aX.width = temp.height;
            aX.size = temp.size - 1;
        }
        return aX;
    } else if(new_size > 4){
        
        int len = new_size - 4;
        for(int i = 1;i <= len ;i++){
            paper temp = aX;
            aX.height = temp.width;
            aX.width = temp.height/2;
            aX.size = temp.size + 1;
        }
        return aX;
    }

}

int main(void){
    int value = 0;

    value = getInput(value);

    paper new_paper = changeSize(value);

    printf("A paper of size A%i is %g by %g mm\n", new_paper.size, new_paper.width, new_paper.height);
    return 0;
}
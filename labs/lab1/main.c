#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LENGTH 255

int getInput(int value){
    bool invalidInput = false;
    char input[MAX_LENGTH];
    // char *value[MAX_LENGTH];

    int length;
    do{
        //Reset in case of second try
        invalidInput = false;

        printf("Which size do you want to calculate?\nA");

        fgets(input, MAX_LENGTH, stdin);
        
        
        //Check input length
        length = strlen(input);
        // printf("%c\n", input[length]);

        if(length > 4){
            puts("You cannot enter more than 4 characters! Maximum size is 1000, asshole.");
            invalidInput = true;
        
        } else{
            //-1 for null character
            for(int i = 0; i < length-1; i++){
                char c = input[i];

                //Check if numeric characters
                if(!( 0x30 <= c && c <= 0x39)){
                    puts("Must be numeric characters only, please!");
                    invalidInput = true;
                    break;
                }
            }
        }
    } while(invalidInput);

    //Convert to int
    sscanf(input, "%i", &value);
    return value;
}

int main(void){
    int value = 0;
    printf("%d",getInput(value));
    return 0;
}
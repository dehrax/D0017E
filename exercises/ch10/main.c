#include <stdio.h>
#include <string.h>

//10.4
#if 0
void substring(char* source, int start, int count, char* result){
    int len = strlen(source);
    if(start + count > len){
        count = len - start;
    }

    for(int i = 0;i<count;i++){
        result[i] = source[start + i];
    }
    result[count] = '\0';
}

int main(void){
    char result[10];

    substring("character", 4, 3, result);

    printf("%s\n", result);

    substring ("two words", 4, 20, result);

    printf("%s\n", result);

}
#endif

//10.5
#if 1
int findString(char* source, char* search){
    int search_len = strlen(search), source_len = strlen(source);
    
    if(search_len > source_len){
        return -1;
    }

    //Start at index
    for(int i = 0; i < source_len; i++){

        for(int j = 0; j <= search_len + 1; j++){
           if(search[j] == '\0'){
               return i;
            } else if(!(source[i + j] == search[j])){
                break;
            }
        }
    }
    
    printf("reached the end");
    return -1;
}

int main (void){
    int index = findString ("a chatterbox", "hat");

    printf("%d\n", index);
}
#endif
#include <stdio.h>
#include <ctype.h>
#define BUFFER_SIZE 255
//16.3
#if 0
int main(void){
    FILE *lowercase = fopen("lowercase.txt", "r+");
    FILE *uppercase = fopen("uppercase.txt", "w+");
    
    if(!lowercase || !uppercase){
        printf("Can't read the file\n");
        return 1;
    }
    char content[BUFFER_SIZE];
    int i = 0;

    
    //TODO handle buffer overflow
    while(fgets(content, BUFFER_SIZE, lowercase)){
        i = 0;
        while(content[i] != '\0'){
            content[i] = toupper(content[i]);
            i++;
        }
        fputs(content, uppercase);
    }

    fclose(lowercase);
    fclose(uppercase);

    printf("Done!\n");
    return 0;

}
#endif

//16.4
#if 1
int main(void){
    FILE *firstfile = fopen("first.txt", "r+");
    FILE *secondfile = fopen("second.txt", "r+");
    FILE *output = fopen("result.txt", "w+");

    char firstLine[BUFFER_SIZE];
    char secondLine[BUFFER_SIZE];

    FILE *everythingThatIsLeft;

    if(!firstfile || !secondfile || !output){
        printf("Failed to read files.\n");
        return 1;
    }

    while(fgets(firstLine, BUFFER_SIZE, firstfile) && fgets(secondLine, BUFFER_SIZE, secondfile)){
        fputs(firstLine, output);
        fputs(secondLine, output);
    }

    //Check which one has reached end of file and return the one that hasn't
    everythingThatIsLeft = feof(firstfile) ? secondfile : firstfile;

    while(fgets(firstLine, BUFFER_SIZE, everythingThatIsLeft)){
        fputs(firstLine, output);
    }

    printf("Done!\n");
    return 0;
}
#endif
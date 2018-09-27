#include <stdio.h>
#include <stdbool.h>

//linked list
struct entry{
    int value;
    struct entry* next;
};

//11.2
#if 0

void insertEntry(struct entry* inserted, struct entry* previous){
    inserted->next = previous->next;
    previous->next = inserted;
}

int main(void){
    struct entry last = {4, NULL};
    struct entry second = {2, &last};
    struct entry first = {1, &second};

    struct entry third = {3, NULL};

    insertEntry(&third, &second);

    //Pointer to loop through linked list
    struct entry* p = &first;
    
    do{
        printf("%d\n", p->value);
        p = p->next;
    }while(p);
}

#endif

//11.10
#if 1
bool compareStrings(char* source, char* search){

    while(*source == *search){
        if(*source == '\0' && *search == '\0'){
            return true;
        }
        source++;
        search++;
    }

    return false;
}

int main(void){
    printf("%i\n", compareStrings("awesome", "awesome"));
    printf("%i\n", compareStrings("Awesome", "awesome"));
}
#endif
#include <stdio.h>
#include <stdbool.h>


//11.2
#if 0
//linked list
struct entry{
    int value;
    struct entry* next;
};

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
#if 0
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

//Actual 11.10
#if 1
struct entry {
    char word[15];
    char definition[50];
};

int compareStrings(const char* s1, const char* s2){

    while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
        if(*s1 < *s2){
            return -1;
        } else if(*s1 > *s2){
            return 1;
        }
    }
    return 0;
}

int lookup(const struct entry dictionary[], const char search[], const int entries){
    int low = 0;
    int high = entries - 1;
    int mid, result;
    int compareStrings(const char *s1, const char *s2);

    while( low <= high){
        mid = (low + high)/2;
        result = compareStrings(dictionary[mid].word, search);

        if(result == -1)
            low = mid + 1;
        else if (result == 1)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

int main(void){
const struct entry dictionary[100] = {
        {"aardvark", "a burrowing African mammal"},
        {"abyss", "a bottomless pit"},
        {"acumen", "mentally sharp; keen"},
        {"addle", "to become confused"},
        {"aerie", "a high nest"},
        {"affix", "to append; attach"},
        {"agar", "a jelly made from seaweed"},
        {"ahoy", "a nautical call of greeting"},
        {"aigrette", "an ornamental cluster of feathers"},
        {"ajar", "partially opened"}
    };
    int entries = 10;
    char word[15];
    int entry;
    
    int lookup(const struct entry dictionary[], const char search[], const int entries);
    printf("Enter word: ");
    scanf("%14s", word);

    entry = lookup(dictionary, word, entries);

    if(entry != -1)
        printf("%s\n", dictionary[entry].definition);
    else
        printf("Sorry, the word %s is not in my dictionary.\n", word);
    return 0;



}

#endif
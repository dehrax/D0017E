# Lecture 7: Working with structures

Structures, function with structures, initalizing structures

Motivation of structures:

- Store related variables. i.e. date with day, month and year
- Store realted data of __different types__

```c
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(void){
    struct date today;

    //Assign to specific member
    today.month = 12;
    today.day = 25;
    today.year= 2018;

    // In the same order as defined in the struct
    struct date tomorrow = {12, 26 , 2018};

    //Order does not matter
    struct date dayAfterTomorrow = {.year = 2018, .day = 27, .month = 12};

    printf("Today's date is %i/%i/%.2i.\n", today.day, today.month, today.year);
    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.day, tomorrow.month, tomorrow.year);
    printf("dayAfterTomorrow's date is %i/%i/%.2i.\n", dayAfterTomorrow.day, dayAfterTomorrow.month, dayAfterTomorrow.year);

    return 0;
}
```

There are different ways of initializing structs. See example for three different way of assigning values to the structs' members.

## Create library

Create object file

```shell
gcc -c file.c
```

`ar rcs libname.a file.o`

-L. flag says find library. Find `-l{filename}`

`gcc -Wall -o outputName -L. -lfile`
#include <stdio.h>

//lecture example
#if 1
struct date {
    int month;
    int day;
    int year;
};

int main(void){
    struct date today;

    today.month = 12;
    today.day = 25;
    today.year= 2018;

    struct date tomorrow = {12, 26 , 2018};

    struct date dayAfterTomorrow = {.year = 2018, .day = 27, .month = 12};

    printf("Today's date is %i/%i/%.2i.\n", today.day, today.month, today.year);
    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.day, tomorrow.month, tomorrow.year);
    printf("dayAfterTomorrow's date is %i/%i/%.2i.\n", dayAfterTomorrow.day, dayAfterTomorrow.month, dayAfterTomorrow.year);

    return 0;
}
#endif
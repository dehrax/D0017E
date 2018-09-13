#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

//6.2
#if 0
int main(){
    int first, second;

    printf("Give me a number: "); 
    scanf("%i", &first);

    printf("\nGive me a second number: ");
    scanf("%i", &second);
    while(second == 0){
        printf("Can't divide by 0 can we?");
        printf("\nGive me a second number: ");
        scanf("%i", &second);
    }

    printf("\nKthnx, doing little calculation\n");
    sleep(1);
    printf("Okay, we're done. \n%i is %s with %i \n", first, first % second ? "not evenly divisible" : "evenly divisible" , second);
    return 0;
}
#endif

//6.3
#if 0
int main(void){
    int first, second;

    printf("Give me a number:");
    scanf("%i", &first);

    do{
        printf("Divide it by: ");
        scanf("%i", &second);
    }while(second == 0);

    printf("%i divded by %i is %.3f\n", first, second, (float)first/second);
    return 0;
}
#endif

//6.5
#if 0
int main ()
{
    int number, right_digit;
    bool is_negative = false;
     
    printf("Enter your number.\n");
    scanf("%i", &number);

    if(number<0){
        is_negative = true;
        number = number*-1;
    }


    do {
        right_digit = number % 10;
        printf ("%i", right_digit);
        number = number / 10;
    }while( number != 0 );
    printf ("%s\n", is_negative ? "-": "");
    return 0;
}
#endif

//7.2
#if 0
int main (void)
{
    int values[10];
    int index;
    for(int i = 0; i<10;i++)
        values[i] = 0;
    values[0] = 197;
    values[2] = -100;
    values[5] = 350;
    values[3] = values[0] + values[5];
    values[9] =
    values[5] / 10;
    --values[2];
    for ( index = 0; index < 10; ++index )
        printf ("values[%i] = %i\n", index, values[index]);
    return 0;
}
#endif

//7.4
#if 0
int main(void){
    const int length = 10;
    float values[10] = {
        1233.442,
        231324.454532,
        343.43,
        43,
        12.1,
        887,
        11.2,
        2.2,
        1.1,
        3.3
    };
    double sum, average;

    for(int i = 0; i<length; i++){
        sum += values[i];
    }
    average = sum/length;
    printf("%f\n", average);
}
#endif

//8.2
#if 0
int calculateTriangularNumber (int n){
    int i, triangularNumber = 0;
    for ( i = 1; i <= n; ++i )
        triangularNumber += i;
    return triangularNumber;
}

int main (void){
    int number, counter;
    for ( counter = 1; counter <= 5; ++counter ) {
        printf ("What triangular number do you want? ");
        scanf ("%i", &number);
        printf ("Triangular number %i is %i\n\n", number, calculateTriangularNumber(number));
    }
    return 0;
}
#endif

//8.10
#if 0
int prime(int number){
    
    for(int i = 2;i<number; i++){
        if(number%i == 0){
            return 0;
        }
    }
    return 1;
        
}

int main(void){
    printf("32 : %d\n", prime(32));
    printf("7 : %d\n", prime(7));
    printf("11 : %d\n", prime(11));
    printf("122 : %d\n", prime(122));
    printf("1223 : %d\n", prime(1223));
}
#endif

//8.11
#if 1
int arraySum(int array[], int length){
    int sum = 0;

    for(int i = 0; i<length; i++){
        printf("%i\n", array[i]);
        sum += array[i];
    }

    return sum;
}

int main(void){
    int array[5] = {1,2,3,4,5};

    printf("%d\n", arraySum(array, 5));
}


#endif
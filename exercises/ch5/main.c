#include <stdio.h>
//4.2
#if 0
int main(void){
    for(int i = 1; i <= 10; i++){
        printf("n=%d, n²=%d\n", i, i*i);
    }
    return 0;
}
#endif

//4.4
#if 0
int main(void){
    int i;
    long int val = 1;
    for( i = 1; i <= 10; i++){
        
        val = val * i;
        printf("%d! = %ld\n", i, val);
    }
    return 0;
}
#endif

//4.5
#if 0
int main(void){
    int n, two_to_the_n;

    printf("TABLE OF POWERS OF TWO\n\n");
    printf(" n2 to the n\n");
    printf("------------------\n");

    two_to_the_n=1;
    for(n=0;n<=10;++n){
        printf("%2i %i\n",n,two_to_the_n);
        two_to_the_n *= 2;
    }
    return 0;
}
#endif

//4.8

#if 1
int main (void)
{
    int n, number, triangularNumber, counter;
    int i = 0;
    printf("How many triangular numbers do you want to calculate?\n");
    scanf("%i", &counter);
    
    do {
        printf ("What triangular number do you want? ");
        scanf("%i", &number);
        triangularNumber = 0;
            for ( n = 1; n <= number; ++n )
                triangularNumber += n;
        printf ("Triangular number %i is %i\n\n", number, triangularNumber);
        i++;
    }while(i< counter);
    return 0;
}
#endif
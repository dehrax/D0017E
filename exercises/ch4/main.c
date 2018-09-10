#include <stdio.h>

//3.3
// Check a couple of the constants
#if 0
int main(void){
    float first = 123.456;
    //second = 0x10.5; Can't write 10.5 in hexadecimal
    //third = 0X0G1; G is not hexadecimal
    int fourth = 0001;
    int fifth = 0xFFFF;
    long int sixth = 123L;
    long int seven = 0L;
    float eigth = .0001;
    //unsigned double nine = 98.7U; float or double cannot be unsigned
    double ten = -12E-12;
    int eleven = +12;
    printf("%f\n%d\n%d\n%ld\n%ld\n%f\n%g\n%d\n",first, fourth, fifth, sixth, seven, eigth, ten, eleven);
    return 0;
}
#endif

//3.6
#if 0
int main(void){
    double x = 2.55;
    double result = 3*x*x*x + x*x + 6; //Could use math library here
    printf("%f\n", result);
    return 0;
}
#endif

//3.8
#if 1
int main(void){
    int next_multiple1 = 365+7 - 256 % 7;
    int next_multiple2 = 12258 + 23 - 12258 % 23;
    int next_multiple3 = 996 + 4 - 996 % 4;

    printf("%d\n%d\n%d\n", next_multiple1, next_multiple2, next_multiple3);
    
    return 0;
}
#endif

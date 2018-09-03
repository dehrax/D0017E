#include <stdio.h>

#if 1
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
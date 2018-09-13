# Lecture 5: Arrays, software design

Arrays

- arrays
- character arrays

## Arrays

- A set of ordered data items of the same data type

`int values[10]` - an array of integers with length 10 (number of elements). Index 0-9.

You usually use loops to work with arrays.

You can give a initial values to the array.

```c
int integers[5] = {1, 2, 4, 5, 6};
```

C also supports automatic size allocation. `char word[] = {'h', 'e', 'j'}`.

Arrays in C always have a fixed size. See lists for expanding array.

## Multidimensional arrays

```c
int M[4][5] = {
    {1,2,4,5,8},
    {5,7,8,9,5},
    {3,2,4,1,1},
    {7,7,8,6,5}
};
```

To work with a multidimensional you will have o use nested loops.

## Contants

Constants are values which you cannot chnage

```c
const int DAYS_IN_A_YEAR = 365;
```

Constants are usualyy all caps.

```c
//argc = number of arguments in the terminal
//argv = an array of the arguments
int main(int argc, char *argv[]){

}

```

## Software design

Software design is not about writing code. It is about understanding and solving a problem in a good and efficient manner. The design is rarely language dependent.

Flowcharts are good to make a design.
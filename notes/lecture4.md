# Lecture 4 - making decisions

__Program flow__, `if, switch, conditional operator`

## `if`-statement

if can be used to evaluate a condition. If the condition is true, the code body will be executed.

```c
if(number < 0){
    //execute code if number is less than 0
    //otherwise, do nothing
}
```

 You can use `else` if you want something to happen if the condition fails.

 ```c
 if(condition){
     //run if condition truthy
 }
 else{
     //run if condition is falsy
 }
 ```

 You can check for more conditions!

 ```c
 if(condition){

 }
 else if(other_condition){

 }
 else{

 }
 ```

 [JPL C coding standard. Good stuff.](https://lars-lab.jpl.nasa.gov/JPL_Coding_Standard_C.pdf)

## Ternary operator

A one-line if-statement

```c
y = (x >= 12) ? 0 : 1;

//is equal to

if(x >= 12){
    y = 0;
} else{
    y = 1;
}
```

## `switch`-statements

```c
switch(/*variable or char*/){
    case 'Y':
    case 'y':
        //Do something
        break;
    case 'N':
        //Do something else
        break;
    default:
        //All other cases
}
```

Much more compact compared to if statements. Execution of the other cases continues if no break statement is included.
# Lecture 6: Functions

___Arguments, return types, variable scopes, recursion, libraries, software licenses___

## Functions

```c
//return type, argument1: argc argument2: argv[]
//return 1
int main(int argc, char* argv[]){
    //code
    return 1; //not ok
}
```

A function is a little bit like a black box. You give it some arguments or values and receive some output.

Make sure your functions have as few side effects as possible, i.e. only manipulate the indata.

## Variable scopes

Global variables exist in the global scope (pretty mych everywhere). Local scope could be inside a function or other code block.

Global variables are declared outside of the function declarations. Naming them in a unique manner is important to avoid colisison with local variables. One way to do it could be to begin with an `_` or to write the variable name in all caps.
 `_IMPORTANT_GLOBAL_VARIABLE`

## `static` variables

 2 different usages.

- Local
  - Local static: will be saved between function calls within the context of the function
  - Local non-static: variable will be reinitialized every function call.
- Global
  - global static: the variable is only relevant to the current C file.

Be wary of the side effects when using `static` variables.

## Recursion

A function which calls itself. Factorial as example, mathematically defined as `n! = n* (n-1)!`

```c
int factorial(unsigned int n){
    if(n==0)
        return 1;
    else
        return n * factorial(n-1);
}
```

It could be solved by using a `for`-loop, which would be faster, but recursion could be easier to understand and implement.

## Libraries

Libraries are pre-written code which can be reused. One exmaple is `stdio.h` which contains function to interact with the systemm.

A library could contain anything, like functions for networking, mathematicla calculations or interaction with some kinds of hardware.

Different sources:

- Home made
- Open source
- Commercial

## Software licenses

### Closed source

- Used by companies for commercial purposes
- Cannot be distributed openly

### Open source

- Used by open source projects
- Usually free to distribute and use
- Examples:
  - Apache 2.0
  - MIT
  - Eclipse
  - BSD
  - GPL

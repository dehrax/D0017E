# Lecture 1 - Introduction
___Introduction to Programming for Engineers (D0017E)___

Jens Eliasson, _jens.eliassson@ltu.se_

EISLAB - Luleå University of Technology

(CI Environment for correcting exercises)

Typical Hello World program

```c
#include <stdio.h>

void main(void) { // void means return nothing, void arguments menas no args
    printf("Hello world!\n);
}
```

## Build process

code (hello.c) -> compiler (gcc.exe) -> object code (hello.o) -> linker (gcc.exe) -> executable (hello.exe)

```shell
##-o output filename
§ gcc -o hello hello.c
§ hello
```

## Software development basics

- Get indata (keyboard, files, network etc...)
- Produce outdata (screen, ptiner, file, network...)
- Mathematical operations
- Conditional operation
- Repetitions, loops
- The art of programming is to combine  these basic building blocks into larger applications

Also Test Driven Development is nice.

## Bugs

A factor of 10 in cost for each step the bug is not identified

- Syntax errors
  - Source code does not follow language rules
- Runtime errors
  - Program compiles, but execution is aborted
- Semantic errors
  - THe program runs and finishes, but produce sdifferent result than planned. <--- __UNIT TESTS!__
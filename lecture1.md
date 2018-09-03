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
  - The program runs and finishes, but produces different result than planned. <--- __UNIT TESTS!__

## The art of programming

- To learn how to program is:
  - Problem solving
  - A way of thinking
- No tconnected to any specific programming language
  - Almost all languages are similar
- This is not a course in C
  - This is a course in programming
  - We are using C as a tool
  - In other courses there are other languages used
    - Python, assembly, Java, Javascript, etc...

## Variables

C has types. Example: `int` means integer.

`%d` is string replacement for integers.

```c
int sum = 20 + 30;
printf("The sum is %d\n", sum);
```

## Embedded systems

Designed to act with the physical world.
I/O is a coffee machine or lamps. Cool stuff. Sensors and stuff. IoT and Cyber-physical Systems (CPS).
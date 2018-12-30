# D0017E - Introduktion till programmering för ingenjörer
[![CodeFactor](https://www.codefactor.io/repository/github/dehrax/d0017e/badge)](https://www.codefactor.io/repository/github/dehrax/d0017e)[![Codacy Badge](https://api.codacy.com/project/badge/Grade/81558d48d84a465780e8cf4cddd62bbe)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dehrax/D0017E&amp;utm_campaign=Badge_Grade)

A course in C/C++ at LTU, Luleå University of Technology. D0017E. Introduktion till programmering för ingenjörer. This repository is meant to keep track of all the exercises, regardless of computer, and to explore some GitHub functionality such as project management.

## Setup
The setup required to run the files:

### Exercises
Each chapter has its own `main.c` file. Each exercise is seperated by conditional preprocessor statements.

```c
#if 0
...
//This code doesn't run
#endif

#if 1
//This code runs
#endif
```
They are usually divided into different main functions, so it is only possible to have one `if`-block active when compiling.

### Project
Just go into [`/labs/lab2`](https://github.com/dehrax/D0017E/tree/master/labs/lab2) and run `make` to compile the program.

## Found a problem, or a better solution?
[File a bug report!](https://github.com/dehrax/D0017E/issues/new/choose)

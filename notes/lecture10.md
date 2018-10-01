# Lecture 10 - The preprocessor and software development

The preprocessor runs before the program is compiled.

```c
#define VAR 2
#ifdef UNIX
//Do UNIX specific operations
#endif

//Macro
#define MAX(x, y) x > y ? x : y
```
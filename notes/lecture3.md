# Lecture 3: Program looping

___Loops, relational operators, program input___

## For loop

- Initalization
- Condition
- Increment

```c
int i;

for (i = 0; i <= 12; i++){
    doSosomethingWith(i);
}
```

## Relational operators

- `==` : Equal to
- `!=` : Does not equal to
- `<` : Less than
- `<=` : Less than or equal

...

## When to use different loops

- `for` if know start and end
- `while` only has a condition for when the loop should be run

```c
while(/*condition*/){
    //code
}
```

- `do while` executes before checking condition. When you want it to run at least one time.

```c
do{
    //code, maybe check for input
} while(/*condition*/);
```

use `break;` to exit a loop

```c
while(true){
    if(/*condition*/){
        break; //exits loops
    }
    if(/*condition*/){
        continue; //exits current iteration of loop
    }
}

```

## User input to terminal programs

- `scanf()`

```c
int main(){
    char str[100];

    printf("Enter name: ");
    scanf("%s", str);

    printf("Entered Name: %s\n", str);

    return 0;
}

```

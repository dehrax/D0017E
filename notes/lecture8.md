# Lecture 8: Character strings

___Array of characters, variable length char strings, escape chars, string operations, constant strings____

## Array of chars

A string is an array of characters.

`char word [] = {'H','e','l','l','o'}`

Add a null sign `\0` to declare where the information ends.

## Escape characters

Some usual examples

| Character     | Description|
| ------------- |:-------------:|
| `\n`          | new line                      |
| `\0`          | null character, end of string |
| `\r`          | Carriage return               |
| `\t`          | Tab                           |
| `\Unnnnnnnn`  | Universal character name      |
| `\a`          | audible alert                 |

## String operations

```c
#include <string.h>
#include <strings.h>
```

These libraries have good functions for working with strings.

## String comparison

Strings in C can only be compared by checking that each character in the string array is equal.
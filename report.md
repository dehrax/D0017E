# Mini MATLAB - Technical report

## Difficulties and solution

### Handling input

It is hard because of it is supposed to handle both inline arithemtic and commands.
Solution: Check each character and look for whitespace or '='-signs. Make a long list of if-statements, taking the arguments and formatting them for the proper function.

### Element-wise operations

To make it easy to implement new element-wise functions for vectors we created two functions; One to handle do operations on elements in a single vector and another to do operations between two vectors' elements.
# Documentation

## Commands

### `help`
          
Displays all available commands and how to use them.

### `vars`

Displays all scalars and their values.

### `quit` or `exit`

Quits them program. `exit <error code>` quits the program with the given error code.

### `set a <num>`

Sets the value of a scalar `a` to `<num>`. `set a 21.2` gives `a = 21.2`.

### `clear a`

Sets the given variable to 0. Works for both scalars and vectors.

### `array A <start> <end>`

Assigns the array `A` with evenly spaced values between `start` and `end`.

### `sin <output> <input>`

Sets the `output`-vector to sinus of the respective elements in `input`.

### `show A`

Displays the given variable, both vector and scalar.

### `event <output> <input>`

Identifies values over `0.5` with a bigger sample size than `10` in the `input` vector and sets all other values to 0 in the `output`.

### `debounce A <num>`

Identifies values in `A` smaller than 0.5 and bigger than 3.0, and sets them to 0.0 and 3.30 respectively.

### `exportCSV A <file name>`

Exports a vector `A` as a csv-file.

### `importCSV A <file name>`

Imports a csv-file to a vector `A`.

### `exportMAT A <file name>`

Exports a given vector `A` to a `.mat`-file.

### `showFile`

Displays a given csv-file.
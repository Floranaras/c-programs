# Practice Exercise - 1D Arrays

> *If you don't have a built-in markdown viewer, you can copy the content of this file and paste it into <https://markdownlivepreview.org/> to view it formatted.*

The goal of this exercise is to:

- Design and implement fundamental algorithms on 1D arrays
- Observe proper code documentation
- Review and strengthen previously learned concepts

## Folder Content

- [`PRACTICE-1D-ARRAYS-LastName.c`](PRACTICE-1D-ARRAYS-LastName.c): The skeleton code containing some initial code that you need to complete
- [`bbtest.c`](bbtest.c): The source code for facilitating black box testing (compile it first)
  - Sample usage after compiling in Mac/Linux:

    ```shell
    ./bbtest EXPECTED_OUTPUT_FILE ACTUAL_OUTPUT_FILE
    ```

  - Sample usage after compiling in Windows:

    ```shell
    bbtest EXPECTED_OUTPUT_FILE ACTUAL_OUTPUT_FILE
    ```

- [`helper.c`](helper.c): Contains the function prototypes of the functions that you need to implement, as well as helper functions for completing the exercise

- `input#.txt`: Sample input when running the program
- `expected#.txt`: The expected output when the program is run against the corresponding `input#.txt`
  - `input1.txt` is matched to `expected1.txt`; `input2.txt` is matched to `expected2.txt`; and so on

## Restrictions

While you are in the PROG series, you are **NOT ALLOWED** to do the following:

- Declare and use global variables (i.e., variables declared outside any function)
- Use `exit`, `goto` (i.e., to jump from code segments to code segments), `break` (except in `switch` statements), or `continue` statements
- Use `return` statements to prematurely terminate a loop, function, or program
- Use `return` statements in `void` functions
- Call the `main()` function to repeat the process instead of using loops

In addition to the general restrictions above:

- You are **NOT ALLOWED** to include other library/header other than those already in the template

## Activity Instructions

1. Read and understand the materials provided to you. Instructions for the functions you need to complete are in the coding activity template.
2. Implement your solution. Ensure that your final solution is able to compile with the following command:

    ```shell
    gcc -Wall -std=c99 <filename.c> -o <output>
    ```

3. Your program must be able to reproduce the same expected output.

## I/O Format

### Input Format

```text
<array size>

<array element 0>
<array element 1>
  .
  .
  .
<array element size-1>
```

### Output Format

```text
<displayArray()>
Array Size: <value>

Min: <value>
Max: <value>
Sum: <value>
Average: <value, 2 decimal places>
# of Positive: <value>
# of Negative: <value>
# of Odd: <value>
# of Even: <value>
isInList-63: <value>
isInList-45: <value>
```

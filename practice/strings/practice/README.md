# Course List: A Coding Exercise on 2D Array of Strings

> *If you don't have a built-in markdown viewer, you can copy the content of this file and paste it into <https://markdownlivepreview.org/> to view it formatted.*

The goal of this exercise is to:

- Design and implement algorithms on a 2D array of strings
- Design and implement algorithms using the 4 string functions (`strlen`, `strcpy`, `strcat`, `strcmp`)
- Observe proper code documentation
- Review and strengthen previously learned concepts

## Folder Content

- [`COURSELIST-LastName.c`](COURSELIST-LastName.c): The skeleton code containing some initial code that you need to complete
- [`main.c`](main.c) – Contains the `main()` function for testing purposes
- [`helper.c`](helper.c): Contains the function prototypes of the functions that you need to implement, as well as helper functions for displaying the output
- [`input.txt`](input.txt): Sample input when running the program
- [`expected.txt`](expected.txt): The expected output when the program is run against [`input.txt`](input.txt)

## Restrictions

While you are in the PROG series, you are **NOT ALLOWED** to do the following:

- Declare and use global variables (i.e., variables declared outside any function)
- Use `exit`, `goto` (i.e., to jump from code segments to code segments), `break` (except in `switch` statements), or `continue` statements
- Use `return` statements to prematurely terminate a loop, function, or program
- Use `return` statements in `void` functions
- Call the `main()` function to repeat the process instead of using loops

In addition to the general restrictions above:

- You are **NOT ALLOWED** to include other library/header other than those already in the template
- You are **NOT ALLOWED** to use any other string function except for `strlen`, `strcpy`, `strcat`, `strcmp`

## Activity Instructions

1. Read and understand the materials provided to you. Instructions for the functions you need to implement are in the [Problem Statement](#problem-statement).
2. Implement your solution. Ensure that your final solution is able to compile with the following command:

    ```shell
    gcc -Wall -std=c99 <filename.c> -o <output>
    ```

3. Your program must be able to reproduce the same expected output. Take note that the functionality for output formatting is already implemented for you.
4. Bonus points are awarded for proper and complete function documentation. This means it has a function description, a list of parameters with description, and if it returns something, a description of the return value.
   - You may refer to this [link for more information](https://www.doxygen.nl/manual/docblocks.html#cppblock)

## Problem Statement

Your task is to implement a variety of functions involving a 2D array of strings. Some may use the any of the 4 string functions, some may not. Some of these functions may also involve calling prior functions you've already implemented in this exercise.

You are provided with multiple type definitions in this exercise:

- `String`: This is a 1D array of characters that represents any student name or course name string
- `StudentRecord`: This is a 1D array of strings that represents a student record. A student record consists of a student's name and 5 course slots. A course slot can either contain a course or it can be free/empty, as represented by an underscore (`_`). Thus, a single student record looks like:

  ```text
  { <student name>, <course slot 1>, <course slot 2>, <course slot 3>, <course slot 4>, <course slot 5> }
   ```

- `StudentMatrix`: This is a 2D array of strings that represents a student matrix. You can think of this as a table of student records. For example:

  | idx | STUDENT    | COURSE #1  | COURSE #2  | COURSE #3  | COURSE #4  | COURSE #5  |
  |-----|------------|------------|------------|------------|------------|------------|
  | 0   | Alice      | CCPROG2    | CSMATH1    | CCDSTRU    | _          | _          |
  | 1   | Bob        | CCPROG2    | GEUSELF    | _          | _          | _          |
  | 2   | Charlie    | CCDSTRU    | GEARTAP    | LASARE1    | NSTP-01    | GEMATMW    |

### `void populateStudentMatrix(StudentMatrix m, int *nStudents)`

This function is responsible for populating the student matrix `m`. `nStudents` is a pointer to the actual number of students within the matrix. It is initially set to `0`. This function will continuously get input for a whole student record and place it within the matrix until it sees `END`.

For convenience in testing, use input redirection. Refer to [Input Format](#input-format) for more information about the input.

### `int searchStudent(StudentMatrix m, int nStudents, String searchStudentName)`

This function checks if `searchStudentName` is within student matrix `m`. The function returns the index number if found in the matrix, `-1` otherwise.

### `int addCourseToStudent(StudentMatrix m, int nStudents, String searchStudentName, String courseName)`

This function looks for `searchStudentName` within student matrix `m`. If found, it will add `courseName` on the 1st free course slot for that student. The function returns `1` if it was able to successfully add the course to the student's record; `0` if the student was found but there were no course slots left; or `-1` if `searchStudentName` does not exist in the student matrix.

### `void sortCourses(StudentMatrix m, int nStudents)`

This function sorts the courses in each row of student matrix `m` in alphabetical order.

## Input Format

The input will have at least 1 student record before `END`.

```text
<student name A>
<course slot 1>
<course slot 2>
<course slot 3>
<course slot 4>
<course slot 5>

<student name B>
<course slot 1>
<course slot 2>
<course slot 3>
<course slot 4>
<course slot 5>

END
```

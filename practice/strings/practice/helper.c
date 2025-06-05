/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains helper functions for completing the exercise
 ******************************************************************************/

#ifndef HELPER_C // Do not remove this line
#define HELPER_C // Do not remove this line

#include <stdio.h>
#include <string.h>

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONSTANTS and TYPEDEFS
 ******************************************************************************/

#define MAX_STR_LEN 11  // Max string length, including null byte
#define MAX_STUDENTS 10 // Max number of students
#define MAX_COURSES 5   // Max number of courses a student can take

// String for student or course name
typedef char String[MAX_STR_LEN];

// A single row containing student name + up to MAX_COURSES
typedef String StudentRecord[MAX_COURSES + 1];

// 2D array containing all student records
typedef StudentRecord StudentMatrix[MAX_STUDENTS];

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file FLIP7-LastName.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/

void populateStudentMatrix(StudentMatrix m, int *nStudents);
int searchStudent(StudentMatrix m, int nStudents, String searchStudentName);
int addCourseToStudent(StudentMatrix m, int nStudents, String searchStudentName, String courseName);
void sortCourses(StudentMatrix m, int nStudents);

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] HELPER FUNCTIONS
 ******************************************************************************/

/**
 * Prints the separator between the column header and column content
 * @param n Indicates how long the column separator is
 * @param isMiddleColumn Flag for what to end the separator with; 1 means the
 *   separator is for a middle column, 0 means it is for the last column
 */
void printBarrier(int n, int isMiddleColumn)
{
  int i;
  for (i = 0; i < n; i++)
    printf("-");

  if (isMiddleColumn)
    printf(" + ");
  else
    printf("\n");
}

/**
 * Displays the student matrix
 * @param m The student matrix
 * @param nStudents The number of students in the matrix
 */
void displayStudentMatrix(StudentMatrix m, int nStudents)
{
  int i, j;
  printf("%-3s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n", "idx", "STUDENT",
         "COURSE #1", "COURSE #2", "COURSE #3", "COURSE #4", "COURSE #5");
  printBarrier(3, 1);
  printBarrier(10, 1);
  printBarrier(10, 1);
  printBarrier(10, 1);
  printBarrier(10, 1);
  printBarrier(10, 1);
  printBarrier(10, 0);

  for (i = 0; i < nStudents; i++)
  {
    printf("%3d | ", i);
    for (j = 0; j <= MAX_COURSES; j++)
      if (j != MAX_COURSES)
        printf("%-10s | ", m[i][j]);
      else
        printf("%-10s\n", m[i][j]);
  }
  printf("\n");
}

/**
 * Copies the `src` student matrix to `dst` student matrix
 * @param dst The destination student matrix to copy to
 * @param src The source student matrix to copy from
 */
void copyMatrix(StudentMatrix dst, StudentMatrix src)
{
  int i, j;
  for (i = 0; i < MAX_STUDENTS; i++)
    for (j = 0; j <= MAX_COURSES; j++)
      strcpy(dst[i][j], src[i][j]);
}

/**
 * Displays a single test case for Task #2
 * @param m Param #1 for the student function
 * @param nStudents Param #2 for the student function
 * @param searchStudentName Param #3 for the student function
 */
void displayTask2TestCase(StudentMatrix m, int nStudents, String searchStudentName)
{
  int result = 999;
  result = searchStudent(m, nStudents, searchStudentName); // Call student function

  printf("  Is '%s' in the matrix?: ", searchStudentName);
  if (result == -1)
    printf("No (idx = %d)\n\n", result);
  else
    printf("Yes, at idx = %d\n\n", result);
}

/**
 * Displays a single test case for Task #2
 * @param m Param #1 for the student function
 * @param nStudents Param #2 for the student function
 * @param searchStudentName Param #3 for the student function
 * @param courseName Param #4 for the student function
 */
void displayTask3TestCase(StudentMatrix m, int nStudents, String searchStudentName, String courseName)
{
  int result = 999;
  result = addCourseToStudent(m, nStudents, searchStudentName, courseName); // Call student function

  printf("  Adding '%s' to %s's student record: ", courseName, searchStudentName);
  switch (result)
  {
  case 1:
    printf("[%d] Student found! Successfully added course!\n\n", result);
    break;
  case 0:
    printf("[%d] Student found! No more free course slots...\n\n", result);
    break;
  case -1:
    printf("[%d] Student does not exist!\n\n", result);
    break;
  default:
    printf("[%d] Unknown return value...\n\n", result);
    break;
  }
}

/******************************************************************************
 * [DO NOT MODIFY] Main display functions
 ******************************************************************************/

/**
 * Display Task #1 test cases
 */
void displayTask1()
{
  StudentMatrix students;
  int nStudents = 0;

  printf("\n  NOTE: Only Task #1 will use the content of the input file.");
  printf("\n    For the next tasks, input for the test cases are hardcoded.\n\n");

  // Call student function
  populateStudentMatrix(students, &nStudents);

  displayStudentMatrix(students, nStudents);
}

/**
 * Display Task #2 test cases
 */
void displayTask2(StudentMatrix original)
{
  StudentMatrix copy;
  int nStudents = MAX_STUDENTS - 1;
  String testcases[4] = {"Alice", "Evan", "Ina", "Kristoff"};

  // Copy to preserve original matrix
  copyMatrix(copy, original);

  printf("\n  +--------------------+");
  printf("\n  | MATRIX for TASK #2 |");
  printf("\n  +--------------------+\n\n");
  displayStudentMatrix(copy, nStudents);

  printf("\n  TEST CASE #1: First element");
  printf("\n  ----------------------------\n");
  displayTask2TestCase(copy, nStudents, testcases[0]);

  printf("\n  TEST CASE #2: Middle element");
  printf("\n  ----------------------------\n");
  displayTask2TestCase(copy, nStudents, testcases[1]);

  printf("\n  TEST CASE #3: Last element");
  printf("\n  ---------------------------\n");
  displayTask2TestCase(copy, nStudents, testcases[2]);

  printf("\n  TEST CASE #4: Not in matrix");
  printf("\n  ---------------------------\n");
  displayTask2TestCase(copy, nStudents, testcases[3]);
}

/**
 * Display Task #3 test cases
 */
void displayTask3(StudentMatrix original)
{
  StudentMatrix copy;
  int nStudents = MAX_STUDENTS - 1;
  String testcases[5] = {"Darwin", "Bob", "Henry", "Charlie", "Kristoff"};
  String courseToAdd = "<< NEW >>";

  // Copy to preserve original matrix
  copyMatrix(copy, original);

  printf("\n  +-----------------------------+");
  printf("\n  | MATRIX for TASK #3 (before) |");
  printf("\n  +-----------------------------+\n\n");
  displayStudentMatrix(copy, nStudents);

  printf("\n  TEST CASE #1: Student Exists, Add to First Course Slot");
  printf("\n  ------------------------------------------------------\n");
  displayTask3TestCase(copy, nStudents, testcases[0], courseToAdd);

  printf("\n  TEST CASE #2: Student Exists, Add to Middle Course Slot");
  printf("\n  -------------------------------------------------------\n");
  displayTask3TestCase(copy, nStudents, testcases[1], courseToAdd);

  printf("\n  TEST CASE #3: Student Exists, Add to Last Course Slot");
  printf("\n  -----------------------------------------------------\n");
  displayTask3TestCase(copy, nStudents, testcases[2], courseToAdd);

  printf("\n  TEST CASE #4: Student Exists, No More Course Slots");
  printf("\n  --------------------------------------------------\n");
  displayTask3TestCase(copy, nStudents, testcases[3], courseToAdd);

  printf("\n  TEST CASE #5: Student Does Not Exist");
  printf("\n  ------------------------------------\n");
  displayTask3TestCase(copy, nStudents, testcases[4], courseToAdd);

  printf("\n  +----------------------------+");
  printf("\n  | MATRIX for TASK #3 (after) |");
  printf("\n  +----------------------------+\n\n");
  displayStudentMatrix(copy, nStudents);
}

/**
 * Display Task #4 test cases
 */
void displayTask4(StudentMatrix original)
{
  StudentMatrix copy;
  int nStudents = MAX_STUDENTS - 1;

  // Copy to preserve original matrix
  copyMatrix(copy, original);

  printf("\n  +-----------------------------+");
  printf("\n  | MATRIX for TASK #4 (before) |");
  printf("\n  +-----------------------------+\n\n");
  displayStudentMatrix(copy, nStudents);

  // Call student function
  sortCourses(copy, nStudents);

  printf("\n  +----------------------------+");
  printf("\n  | MATRIX for TASK #4 (after) |");
  printf("\n  +----------------------------+\n\n");
  displayStudentMatrix(copy, nStudents);
}

#endif // HELPER_C
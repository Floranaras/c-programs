/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains helper functions for completing the exercise
 ******************************************************************************/
#ifndef HELPER_C
#define HELPER_C

#include <stdio.h>

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONSTANTS
 ******************************************************************************/
#define MAX_SIZE 10 // Max size of the 2D array

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file PRACTICE-1D-ARRAYS-LastName.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/

void numberGrid1(int arr2D[][MAX_SIZE], int n);
void numberGrid2(int arr2D[][MAX_SIZE], int n);
void multiplicationTable(int arr2D[][MAX_SIZE], int n);
void hollowBox(char arr2D[][MAX_SIZE], int n);
void leftPyramid(char arr2D[][MAX_SIZE], int n);
void invertedLeftPyramid(char arr2D[][MAX_SIZE], int n);
void rightPyramid(char arr2D[][MAX_SIZE], int n);
void invertedRightPyramid(char arr2D[][MAX_SIZE], int n);

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] HELPER FUNCTIONS
 ******************************************************************************/

/**
 * [GIVEN] Initializes the number grid with 0
 * @param arr2D The starting address of the array
 * @param arrSize The size of the array
 */
void initializeNumberGrid(int arr2D[][MAX_SIZE], int arrSize)
{
  int i, j;
  for (i = 0; i < arrSize; i++)
    for (j = 0; j < arrSize; j++)
      arr2D[i][j] = 0;
}

/**
 * [GIVEN] Initializes the character grid with '_'
 * @param arr2D The starting address of the array
 * @param arrSize The size of the array
 */
void initializeCharacterGrid(char arr2D[][MAX_SIZE], int arrSize)
{
  int i, j;
  for (i = 0; i < arrSize; i++)
    for (j = 0; j < arrSize; j++)
      arr2D[i][j] = '_';
}

/**
 * [GIVEN] Displays the number grid
 * @param arr2D The starting address of the array
 * @param arrSize The size of the array
 */
void displayNumberGrid(int arr2D[][MAX_SIZE], int arrSize)
{
  int i, j;
  for (i = 0; i < arrSize; i++)
  {
    for (j = 0; j < arrSize; j++)
      printf("%4d ", arr2D[i][j]);
    printf("\n");
  }
}

/**
 * [GIVEN] Displays the character grid
 * @param arr2D The starting address of the array
 * @param arrSize The size of the array
 */
void displayCharacterGrid(char arr2D[][MAX_SIZE], int arrSize)
{
  int i, j;
  for (i = 0; i < arrSize; i++)
  {
    for (j = 0; j < arrSize; j++)
      if (arr2D[i][j] == '_')
        printf("  ");
      else
        printf("%c ", arr2D[i][j]);
    printf("\n");
  }
}

#endif // HELPER_C
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

#define MAX_SIZE 20 // Max number of elements in the array

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file PRACTICE-1D-ARRAYS-LastName.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/

float getAverage(int arr[], int arrSize);
int getMaximum(int arr[], int arrSize);
int getMinimum(int arr[], int arrSize);
int countOdd(int arr[], int arrSize);
int countEven(int arr[], int arrSize);
int countPositive(int arr[], int arrSize);
int countNegative(int arr[], int arrSize);
char isInList(int arr[], int arrSize, int key);

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] HELPER FUNCTIONS
 ******************************************************************************/

/**
 * [GIVEN] Gets the size of the array from the user
 * @param sizeAddr The address on where to store the array size
 */
void getArrSize(int *sizeAddr)
{
  scanf("%d", sizeAddr);
}

/**
 * [GIVEN] Continuously gets input `arrSize` times
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The sum of the array elements
 */
void populateArray(int arr[], int arrSize)
{
  int i;
  for (i = 0; i < arrSize; i++)
    scanf("%d", &arr[i]);
}

/**
 * [GIVEN] Outputs each array element
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 */
void displayArray(int arr[], int arrSize)
{
  int i;
  for (i = 0; i < arrSize; i++)
    printf("%d ", arr[i]);
}

/**
 * [GIVEN] Returns the sum of the array elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The sum of the array elements
 */
int getSum(int arr[], int arrSize)
{
  int i;
  int sum = 0;
  for (i = 0; i < arrSize; i++)
    sum += arr[i];

  return sum;
}

#endif // HELPER_C
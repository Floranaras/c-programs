/******************************************************************************
 * Topic   : Practice 1D Arrays
 * Name    : Ranara, Ramil Carlos
 * Section : S11
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: PRACTICE-1D-ARRAYS-LastName.c
 *     - Example: PRACTICE-1D-ARRAYS-DelaCruz.c
 *
 * 2. Read and understand the problem specs.
 *
 * 3. Compile and run the skeleton code. Observe, trace, and understand what the
 *    skeleton code does before doing any changes.
 *
 * 4. Implement your solution in this file. This is the C source file that you
 *    should submit/upload in AnimoSpace. Follow all the instructions in the
 *    accompanying specifications file and the instructions written (as function
 *    comments) in this file.
 *
 *    Compile:
 *      prompt~> gcc -Wall -std=c99 PRACTICE-1D-ARRAYS-DelaCruz.c -o app
 *
 *    Run in Mac/Linux:
 *      prompt~> ./app
 *
 *    Run in Windows:
 *      prompt~> app
 *
 * 5. Your program must be able to reproduce the same expected output. If
 *    applicable, you may use the included bbtest.c file to streamline the
 *    testing of your program.
 *
 * Prepared by
 * - Email  : kristine.kalaw@dlsu.edu.ph
 * - @author: Kristine Kalaw
 *            Department of Software Technology
 *            College of Computer Studies
 *            De La Salle University
 *
 * Kindly inform me if there are any corrections needed for this template
 ******************************************************************************/

#include "helper.c"

/******************************************************************************
 * [TODO] FUNCTION IMPLEMENTATIONS
 *
 * The section area below is where you will complete the functions as described
 * in the problem specs.
 *
 * For this exercise, you are NOT ALLOWED to define any other convenience/helper
 * function.
 ******************************************************************************/

/**
 * Returns the average of the array elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The average of the array elements
 */
float getAverage(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  return getSum(arr, arrSize) / (arrSize * 1.0); // replace with actual return value
}

/**
 * Returns the highest value among the array elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The highest value among the array elements
 */
int getMaximum(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

	int j;
	int maxIdx = 0;

	for(j = 0; j < arrSize; j++)
	{
		if (arr[maxIdx] < arr[j])
			maxIdx = j; 		
	}

  return arr[maxIdx]; // replace with actual return value
}

/**
 * Returns the lowest value among the array elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The lowest value among the array elements
 */
int getMinimum(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

	int j;
	int minIdx = 0;

	for(j = 0; j < arrSize; j++)
	{
		if (arr[minIdx] > arr[j])
			minIdx = j; 		
	}

  return arr[minIdx];
	// replace with actual return value
}

/**
 * Returns the number of odd elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The number of odd elements
 */
int countOdd(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

	int j;
	int count = 0;

	for (j = 0; j < arrSize; j++)
	{
		if (arr[j] % 2 != 0)
			count++;
	}

  return count; // replace with actual return value
}

/**
 * Returns the number of even elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The number of even elements
 */
int countEven(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
	int j;
	int count = 0;

	for (j = 0; j < arrSize; j++)
	{
		if (arr[j] % 2 == 0)
			count++;
	}

  return count;
   // replace with actual return value
}

/**
 * Returns the number of positive elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The number of positive elements
 */
int countPositive (int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
	int j;
	int count = 0;

	for (j = 0; j < arrSize; j++)
	{
		if (arr[j] > 0)
			count++;
	}

  	return count;

   // replace with actual return value
}

/**
 * Returns the number of negative elements
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return The number of negative elements
 */
int countNegative(int arr[], int arrSize)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

	int j;
	int count = 0;

	for (j = 0; j < arrSize; j++)
	{
		if (arr[j] < 0)
			count++;
	}

  return count;
   // replace with actual return value
}

/**
 * Checks if `key` is in the array
 * @param arr The starting address of the array
 * @param arrSize The size of the array
 * @return 'Y' if key is in the array, 'N' otherwise
 */
char isInList(int arr[], int arrSize, int key)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
	int j = 0;
	
	while (j < arrSize && arr[j] != key)
		j++;

	if (j == arrSize)
		return 'N';
	
	return 'Y';

 // replace with actual return value
}

/******************************************************************************
 * [TODO] COMPLETE THE MAIN FUNCTION
 *
 * This is the main function. The fuctions you implemented above MUST BE CALLED
 * properly here.
 ******************************************************************************/
int main()
{
  int A[MAX_SIZE];
  int nElements; // number of actual elements, nElements <= MAX_SIZE

  getArrSize(&nElements);
  populateArray(A, nElements);

  displayArray(A, nElements);
  printf("\nArray Size: %d\n\n", nElements);

	printf("Min: %d\n", getMinimum(A,nElements));
	printf("Max: %d\n", getMaximum(A,nElements));
	printf("Sum: %d\n", getSum(A,nElements));
	printf("Average: %.2f\n", getAverage(A,nElements));
	printf("# of Positive: %d\n", countPositive(A, nElements));
	printf("# of Negative: %d\n", countNegative(A,nElements));
	printf("# of Odd: %d\n", countOdd(A,nElements));
	printf("# of Even: %d\n", countEven(A,nElements));
	printf("isInList-63: %c\n", isInList(A,nElements,63));
	printf("isInList-45: %c\n", isInList(A,nElements,45));


  return 0;
}
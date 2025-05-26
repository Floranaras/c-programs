#include "functions.c"
#include <stdio.h>

#define SIZE (5)

int main ()
{
	int A[SIZE] = {6, 9, 2, 1, 4};
	
	printf("Before Sort:\n");
	printArr(A,SIZE);
	selectionSort(A, SIZE);
	printf("After Sort:\n");
	printArr(A,SIZE);

	return 0;
}

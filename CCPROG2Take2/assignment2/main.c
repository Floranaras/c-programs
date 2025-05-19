#include <stdio.h>
#include "functions.c"

int main()
{
	int numbers[SIZE] = {2,1,8,4,8,3,7,9,3,1};

	printf("\ngetNextOccurrence: \n");
	printf("Test 1: %d\n", getNextOccurrence(numbers, 3, 3,SIZE));
	printf("Test 2: %d\n", getNextOccurrence(numbers, 2, 0,SIZE));
	printf("Test 3: %d\n", getNextOccurrence(numbers, 8, 1,SIZE));
	printf("Test 4: %d\n", getNextOccurrence(numbers, 8, 2,SIZE));
		
	printf("\nreplaceAll : \n");
	printf("\nBefore: ");
	printArr(numbers, SIZE);
	replaceAll(numbers, 1, 100, SIZE);
	printf("\nAfter: ");
	printArr(numbers, SIZE);

	return 0;
}

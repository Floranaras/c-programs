#include <stdio.h>

void printArr(int* A, int size)
{
	int j;

	printf("\n{\n");
	
	for (j = 0; j < size; j++)
	{
		printf("%d ", A[j]);
	}
	
	printf("\n}\n");
}

void selectionSort(int* A, int size)
{
	int j, k, temp;

	for (j = 0; j < size - 1; j++)
	{
		for (k = j + 1; k < size; k++)
		{
			if (A[j] > A[k])
			{
				temp = A[j];
				A[j] = A[k];
				A[k] = temp;
			}
		}
	}
}

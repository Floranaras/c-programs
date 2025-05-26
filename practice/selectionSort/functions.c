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
	int j, k, temp, minIdx;

	for (j = 0; j < size - 1; j++)
	{
		minIdx = j;

		for (k = j + 1; k < size; k++)
		{
			if (A[minIdx] > A[k])
			{
				minIdx = k;
			}
		}

		if (minIdx != j)
		{
			temp = A[j];
			A[j] = A[minIdx];
			A[minIdx] = temp;
		}
	}
}

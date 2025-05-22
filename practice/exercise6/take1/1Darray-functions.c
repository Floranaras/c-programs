#include <stdio.h>

#define SIZE (5)
#define MAX (10)

void printArr(int* A, int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		printf("%d ", A[j]);
	}

	printf("\n");
}

void initArr(int* A)
{
	int j;

	for (j = SIZE; j < MAX; j++)
	{
		A[j] = 0;
	}
}

int isEqual(int *src, int *dst, int size)
{
    int i = 0, flag = 1;

    while (i < size && flag)
    {
        if (src[i] != dst[i])
            flag = 0;

        i++;
    }

    return flag;
}

void shiftElements (int *A, int size, int idx)
{
	int j;

	for (j = idx; j < size - 1; j++)
	{
		A[j] = A[j+1];
	}

	A[j] = 0;
}

void removeDuplicates(int* A, int size)
{
	int j, k;
	
	for (j = 0; j < size; j++)
	{
		for (k = j + 1; k < size; k++)
		{
			if (A[j] == A[k])	
			{
				shiftElements(A, size, k);
			}
		}
	}
}

void addUnique(int* src, int* dst, int size)
{
	int i, j, found = 0;

	for (i = 0; i < size; i++)
	{
		found = 0;

		for (j = 0; j < size; j++)
		{
			if (src[i] == dst[j])
			{
				found = 1;
			}
		}
		
		if (!found)
		{
			dst[size - 1] = src[i];
			size++;
		}

	}
}

#include <stdio.h>

#define SIZE (10)

void printArr(int arr[], int size)
{
	int j, count = 0;
	
	while (count < size && arr[count] > 0)
	{
		count++;
	}

	printf("\n{\n");
	for (j = 0; j < count; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n}\n");
	
}
int getCountOf(int numbers[], int key, int size)
{
	int j, nFound = 0;

	for (j = 0; j < size; j++)
	{
		if (numbers[j] == key)
		{
			nFound++;
		}
	}

	return nFound;
}

void insertAt(int values[], int idx, int newVal)
{
	int j, count = 0;
	
	while (count < SIZE && values[count] > 0)
	{
		count++;
	}

	if (count >= SIZE)
	{
		count = SIZE - 1;
	}

	for (j = count; j > idx; j--)
	{
		values[j] = values[j-1];
	}
	
	values[idx] = newVal;
}



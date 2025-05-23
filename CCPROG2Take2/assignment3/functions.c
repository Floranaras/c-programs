#include <stdio.h>

void initArr(int arr[], int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		arr[j] = 0;
	}			
}

void inputArr(int arr[], int size)
{
	int j = 0;
	int input = 1;	
	
	while (j < size && input > 0)
	{
		scanf("%d", &input);
		arr[j] = input;
		j++;
	}
}
void printArr(int arr[], int size)
{
	int j;

	printf("\n{\n");

	for (j = 0; j < size; j++)
	{
		printf("%d ", arr[j]);
	}

	printf("\n}\n");
}
int findIdx(int arr[], int size)
{
	int j = 0;

	while(j < size && arr[j] != 0)
	{
		j++;
	}
		
	return j;
}

int isFound(int arr[], int val, int idx)
{
	int j = 0;

	while (j < idx && val != arr[j])
	{
		j++;
	}

	if (j == idx)
	{
		return 0;
	}

	return 1;
}

void getUnion(int setA[], int setB[], int size)
{
	int j, aIdx, bIdx;

	aIdx = findIdx(setA, size);
	bIdx = findIdx(setB, size);

	for (j = 0; j < bIdx && aIdx < size; j++)
	{
		if (!isFound(setA, setB[j], aIdx))
		{
			setA[aIdx] = setB[j];
			aIdx++;
		}
	}
}


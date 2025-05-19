#define SIZE (10)

int getNextOccurrence(int* numbers, int key, int startIdx, int size)
{
	int j = startIdx + 1;
	int flag = 0;
	int idx = -1;

	while (j < size && !flag)
	{
		if (numbers[j] == key)
		{
			flag = 1;
			idx = j;
		}

		else 
		{	
			j++;
		}
	}

	return idx;
}

void replaceAll(int* numbers, int oldVal, int newVal, int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		if (numbers[j] == oldVal)
		{
			numbers[j] = newVal;
		}
	}
}

void printArr(int* A, int size)
{
	int j;

	for (j = 0; j < size; j++)
	{
		printf("%d ", A[j]);
	}

	printf("\n");
}

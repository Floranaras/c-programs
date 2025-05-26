#include <stdio.h>

#define SIZE 6

int isPalendrome(int* numbers, int size)
{
	int j, k, flag = 1;

	for (j = 0, k = size - 1; j < k && flag; j++, k--)
	{
		if (numbers[j] != numbers[k])
		{
			flag = 0;
		}
	}

	return flag;
}

int isEqual(int* A, int* B, int size)
{
	int j;

	for(j = 0; j < size && A[j] == B[j]; j++);

	if (j == size)
		return 1;

	return 0;
}

int main()
{
	int numbers[SIZE] = {3,2,2,2,5};
	int A[SIZE] = {3,2,2,2,5};
	int B[SIZE] = {5,2,2,2,5};

	if (isEqual(A,B,SIZE))
	{
		printf("Is a equal\n");
	}	
	else
	{	
		printf("Is NOT a equal\n");
	}

	return 0;
}

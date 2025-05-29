#include <stdio.h>
#include <string.h>

typedef char string10[11];
typedef char string30[31];
typedef char string50[51];


void sort(string10 words[], int size)
{
	int j, k;
	string10 temp;

	for (j = 0; j < size - 1; j++)
	{
		for (k = 0; k < size - j - 1; k++)
		{
			if (strcmp(words[k],words[k+1]) > 0)
			{
				strcpy(temp, words[k]);
				strcpy(words[k], words[k+1]);
				strcpy(words[k+1], temp);
			}
		}

	}
}

void printArr(string10 arr[], int size)
{
	int j;
	
	printf("\n{\n");
	for (j = 0; j < size; j++)
	{
		printf("%s ", arr[j]);
	}
	printf("\n}\n");

}


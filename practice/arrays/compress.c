#include <stdio.h>
#define SIZE (4)

void printArr(int matrix[][SIZE/2]) {
	int j, k;

	printf("\n{\n");

	for (j = 0; j < SIZE/2; j++)
	{

		for (k = 0; k < SIZE/2; k++)
		{
			printf("%d ", matrix[j][k]);
		}

		printf("\n");
	}

	printf("}\n");
}

void compressArr(int matrix[][SIZE], int comp[][SIZE/2])
{
	int h, i, j, k, count, sum;

	for (h = 0; h < SIZE; h += 2)	
	{
		for (i = 0; i < SIZE; i += 2)
		{
			sum = 0;
			count = 0;	

			for (j = h; j < h + 2 ; j++) 
			{
				for (k = i; k < i + 2; k++)
				{
					sum += matrix[j][k];
					count++;
				}	
			}		
			comp[h/2][i/2] = sum /= count;
		}
	}
}

int main()
{
	int matrix[SIZE][SIZE] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int comp[SIZE/2][SIZE/2];

	compressArr(matrix, comp);
	printArr(comp);
}

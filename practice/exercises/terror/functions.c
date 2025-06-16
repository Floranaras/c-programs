#include <stdio.h>
#define MAX (10)

void printArr(int A[][MAX], int n)
{
	int j, k;

	printf("\n{\n");

	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			printf("%d ", A[j][k]);
		}

		printf("\n");
	}

	printf("}\n");
}

int isUnique(int A[][MAX], int input, int row, int col, int n)
{
	int j, k;
	int rep = 1;

	for (j = 0; j < n && rep == 1; j++)
	{
		for (k = 0; k < n && rep == 1; k++)
		{
			if (j < row || (j == row && k < col))
			{
				if (A[j][k] == input)
				{
					rep = 0;
				}
			}
		}
	}
	return rep;
}

void input2D(int arr[][MAX], int n) 
{
	int j, k = 0;	
	int input;

	for (j = 0; j < n; j++)
	{
		printf("Elements for Row %d\n", j + 1);
		
		k = 0;
		while(k < n)
		{
			scanf("%d", &input);
			getchar();
			if (isUnique(arr,input,j,k,n) == 1)
			{
				arr[j][k] = input;
				k++;
			}

			else
			{
				printf("=============================");
				printf(" \nElements must be unique\n");
				printf("=============================\n");
			}
		}
	}
}

void addMatrix(int A[][MAX], int B[][MAX], int sum[][MAX], int n)
{
	int j, k;

	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			sum[j][k] = A[j][k] + B[j][k];
		}
	}
}

void transMatrix(int A[][MAX], int trans[][MAX], int n)
{
	int j, k;

	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			trans[k][j] = A[j][k];
		}
	}
}

void getCofactor(int n, int A[][MAX], int temp[][MAX], int p, int q) 
{
    int j, k;
    int rowOffset = 0;

    for (j = 0; j < n - 1; j++) 
	{
        if (j == p) 
		{
            rowOffset = 1;
        }

        k = 0;
        int colOffset = 0;
		
        while (k < n - 1) 
		{
            if (colOffset == q) 
			{
                colOffset++;
            }

            temp[j][k] = A[j + rowOffset][colOffset];
            k++;
            colOffset++;
        }
    }
}

void getDeterminant(int n, int A[MAX][MAX], int *det) 
{
    int j, sign, subDet;
    int temp[MAX][MAX];
    *det = 0;

    if (n == 1) 
	{
        *det = A[0][0];
    }

    if (n == 2) 
	{
        *det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }

    if (n > 2) 
	{
        sign = 1;
        for (j = 0; j < n; j++) 
		{
            getCofactor(n, A, temp, 0, j);
            getDeterminant(n - 1, temp, &subDet);
            *det = *det + sign * A[0][j] * subDet;
            sign = -sign;
        }
    }
}

void checkDiagonalDominance(int A[][MAX], int n)
{
    int i, j;
    int isDominant = 1;

    for (i = 0; i < n; i++)
    {
        int diag = A[i][i] >= 0 ? A[i][i] : -A[i][i];
        int sum = 0;

        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                int absVal = A[i][j] >= 0 ? A[i][j] : -A[i][j];
                sum += absVal;
            }
        }

        if (diag <= sum)
        {
            isDominant = 0;
            printf("\nRow %d is NOT diagonally dominant.\n", i + 1);
        }
    }

    if (isDominant == 1)
    {
        printf("\nMatrix is diagonally dominant.\n");
    }
}

void compareMatrices(int A[][MAX], int B[][MAX], int n)
{
    int i, j;
    int areEqual = 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != B[i][j])
            {
                if (areEqual == 1)
                {
                    printf("\nMatrices are NOT equal.\n");
                    areEqual = 0;
                }

                printf("Mismatch at position [%d][%d]: A=%d, B=%d\n", i, j, A[i][j], B[i][j]); } }
    }

    if (areEqual == 1)
    {
        printf("\nMatrices are equal.\n");
    }
}

void sumRow(int B[][MAX], int n, int* rowSums) 
{ 
	int j, k;
	int sum = 0;

	for (j = 0; j < n; j++)
	{
		sum = 0;

		for (k = 0; k < n; k++)
		{
			sum += B[j][k];
		}

		rowSums[j] = sum;
	}
}

void sumCol(int B[][MAX], int n, int colSums[])
{
    int j, k;

    // Initialize all column sums to 0
    for (k = 0; k < n; k++)
    {
        colSums[k] = 0;
    }

    // For each column k, sum all rows j
    for (k = 0; k < n; k++)
    {
        for (j = 0; j < n; j++)
        {
            colSums[k] += B[j][k];
        }
    }
}

void sumsArr(int B[][MAX], int n) 
{
	int colSums[n];
	int rowSums[n];
	int j;

	sumRow(B, n, rowSums);
	sumCol(B, n, colSums);

	printf("\n");

	for (j = 0; j < n; j++)
	{
		printf("Sum of Row %d: %d\n", j + 1, rowSums[j]);
	}

	for (j = 0; j < n; j++)
	{
		printf("Sum of Column %d: %d\n", j + 1, colSums[j]);
	}
}

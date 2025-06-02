#include <stdio.h>
#define NROW (3)
#define NCOL (3)

void printArr(int matrix[][NCOL])
{
	int j, k;

	printf("\n{\n");

	for (j = 0; j < NROW; j++)
	{

		for (k = 0; k < NCOL; k++)
		{
			printf("%d ", matrix[j][k]);
		}

		printf("\n");
	}

	printf("}\n");
}
void inputRows(int* RowA, int* RowB, int* multipler)
{
	printf("Input Row 1st Term: ");
	scanf("%d", RowA);
	printf("Input Row 2nd Term: ");
	scanf("%d", RowB);
	printf("Input Multipler: ");
	scanf("%d", multipler);

	*RowA -= 1;
	*RowB -= 1;
}

void swapRows(int matrix[][NCOL])
{
	int RowA;
	int RowB;
	int j;
	int temp;

	printf("Input Row 1st Term: ");
	scanf("%d", &RowA);
	printf("Input Row 2nd Term: ");
	scanf("%d", &RowB);
	RowA -= 1;
	RowB -= 1;

	for (j = 0; j < NCOL; j++)	
	{
		temp = matrix[RowA][j];
		matrix[RowA][j] = matrix[RowB][j];
 		matrix[RowB][j] = temp;
	}	

}

void multiRow(int matrix[][NCOL])
{
	int row;
	int multipler;
	int j;

	printf("Input Row: ");
	scanf("%d", &row);
	printf("Input Multipler: ");
	scanf("%d", &multipler);
	
	row -= 1;

	for (j = 0; j < NCOL; j++)
	{
		matrix[row][j] *= multipler;
	}
	
}

void divideRow(int matrix[][NCOL])
{
	int row;
	int divider;
	int j;

	printf("Input Row: ");
	scanf("%d", &row);
	printf("Input Divider: ");
	scanf("%d", &divider);
	
	row -= 1;

	for (j = 0; j < NCOL; j++)
	{
		matrix[row][j] /= divider;
	}
	
}

void addRowOp(int matrix[][NCOL])
{
	int RowA, RowB, multipler;
	int j;
	inputRows(&RowA, &RowB, &multipler);
	
	for (j = 0; j < NCOL; j++)
	{
		matrix[RowA][j] += multipler * matrix[RowB][j];
	}
}
void subRowOp (int matrix[][NCOL])
{
	int RowA, RowB, multipler;
	int j;
	inputRows(&RowA, &RowB, &multipler);

	for (j = 0; j < NCOL; j++)
	{
		matrix[RowA][j] -= multipler * matrix[RowB][j];
	}
}

void elimateRow(int matrix[][NCOL])
{
	int choice;
	
	do 
	{
		printf("\n===ROW OPERATIONS===\n");
		printf("1] Swap: Rn <-> Rm\n");
		printf("2] Multiplier: X * Rn\n");
		printf("3] Divider: Rn / X\n");
		printf("4] Rn + X * Rm\n");
		printf("5] Rn - X * Rm\n");
		printf("Select operation: ");
		scanf("%d", &choice);
	
		switch (choice)
		{
			case 1: swapRows(matrix); break;
			case 2: multiRow(matrix); break;
			case 3: divideRow(matrix); break;
			case 4: addRowOp(matrix); break;
			case 5: subRowOp(matrix); break;
			default: printf("Invalid choice");	
		}
	} while (!(choice >= 1 && choice <= 5));
}

int main ()
{
	int matrix[NROW][NCOL] = {{1,2,3},{4,5,6},{7,8,9}};
	char choice;

	printArr(matrix);

	do 
	{	
		elimateRow(matrix);
		printArr(matrix);
		printf("Do you wanna do another operation (y/n): ");
		scanf(" %c", &choice);
	} while (choice == 'y');

	return 0;
}

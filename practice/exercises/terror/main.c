#include "functions.c"

int main()
{
	int n;

	// Input n and m for arrays
	printf("Input the size n: ");
	scanf("%d", &n);

	int A[MAX][MAX], B[MAX][MAX], sum[MAX][MAX], trans[MAX][MAX], det;

	input2D(A, n);
	input2D(B, n);

	printf("\nSum of the Arrays\n");
	addMatrix(A, B, sum, n);
	printArr(sum, n);

	printf("\nTransposed Matrix A\n");
	transMatrix(A, trans, n);
	printArr(trans,n);

	getDeterminant(n, A, &det);
	printf("\nDeterminant of A: %d\n", det);

	checkDiagonalDominance(A, n);

	compareMatrices(A, B, n);

	sumsArr(B, n);
	
	return 0;
}

#include <stdio.h>
#include "arrays-functions.c"

int main()
{
    int n = nSIZE;
    int m = sSIZE;
    int A[] = {2, 3, 4, -2, 32};
    int B[] = {4, 3, 4, -8, 31};
    int C[n];
    char S[] = {'C','o','M','p','r','o','2'};
    int M[nROW][nCOLUMN]=  {
        {1, 2 ,3 ,4, 5},
        {0, 1, 0, 0 ,0},
        {0, 0, 1, 0 ,0},
        {0, 0, 0, 1 ,0},
        {0, 0, 0, 0, 1}
    };
    int T[nROW][nCOLUMN];
    int P[nROW][nCOLUMN];

    // Easy Mode
    printf("IsIncreasingOrder: %d\n", IsIncreasingOrder(A, n));
    printf("CountOdd: %d\n", CountOdd(A, n));
    printf("Minimum: %d\n", Minimum(A, n));
    printf("Maximum: %d\n", Maximum(A, n));
    printf("Sum: %d\n", Sum(A, n));
    printf("Average: %.2f\n", Average(A, n));

    // Hard Mode
    printf("CountUpper: %d\n", CountUpper(S, m));
    printf("ConvertUpper: ");
    ConvertUpper(S,m);
    printf("MaxCopy: ");
    MaxCopy(C, A, B, n);
    printf("IsIdentityMatrix: %d\n", IsIdentityMatrix(M));
    printf("TransposeMatrix: \n");
    TransposeMatrix(M,T);
    printf("MultiplyMatrix:\n");
    MultiplyMatrix(P, M, T);
    PrintColumnMajorOrder(M);
    return 0;
}

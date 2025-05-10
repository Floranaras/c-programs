#define nSIZE (5)
#define sSIZE (7)
#define nCOLUMN (5)
#define nROW (5)

void printArray(char* S, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%c ", S[i]);
    }
    
    printf("\n");
}

void printIntArray(int* A , int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
}

void print2DArray(int A[][nCOLUMN])
{
    int i, j; 

    printf("2D Matrix:\n");

    for (i = 0; i < nROW; i++)
    {
        for (j = 0; j < nCOLUMN; j++)
        {
            printf("%d ", A[i][j]);
        }
        
        printf("\n");
    }
}

int IsIncreasingOrder(int* A, int n)
{
    int i, nNum = 1;

    for (i = 0; i <= n - 2; i++)
    {
        if (!(A[i] <  A[i+1]))
        {
            nNum = 0;
        }
    }

    return nNum;
}

int CountOdd(int* A, int n)
{
    int i, nCount = 0;

    for (i = 0; i < n; i++)
    {
        if (A[i] % 2 != 0)
        {
            nCount++;
        }
    }

    return nCount;
}

int Minimum(int* A, int n)
{
    int i, min = A[0];

    for (i = 1; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
}

int Maximum(int* A, int n)
{
    int i, nMax = A[0];

    for (i = 1; i < n; i++)
    {
        if (A[i] > nMax)
        {
            nMax = A[i];
        }
    }

    return nMax;
}

int Sum(int* A, int n)
{
    int i, nSum = 0;

    for (i = 0; i < n; i++)
    {
        nSum += A[i];
    }

    return nSum;
}

float Average(int* A, int n)
{
    int fTotal = Sum(A, n);

    return fTotal * 1.0 / n;
}

int CountUpper(char* S, int n)
{
    int i, nCount = 0;

    for (i = 0; i < n; i++)
    {
        if (S[i] >= 'A' && S[i] <= 'Z')
        {
            nCount++;
        }
    }

    return nCount;
}

void ConvertUpper(char* S, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (S[i] >= 'a' && S[i] <= 'z')
        {
            S[i] -= 32;
        }
    }

    printArray(S, n);
}

void MaxCopy(int* C, int* A, int* B, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (A[i] > B[i])
        {
            C[i] = A[i];
        }

        else if (B[i] > A[i])
        {
            C[i] = B[i];
        }

        else
        {
            C[i] = A[i];
        }
    }

    printIntArray(C, n);
}

int IsIdentityMatrix(int M[][5])
{
    int i, j, flag = 1;

   for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                if (M[i][j] != 1)
                {
                    flag = 0;
                } 
            }

            else
            {
                if (M[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }

    return flag;
}

void TransposeMatrix(int M[][5], int T[][5])
{
    int i, j;

    for (i = 0; i < nROW; i++)
    {
        for (j = 0; j < nCOLUMN; j++)
        {
            T[j][i] = M[i][j];
        }
    }

    print2DArray(T);
}

void MultiplyMatrix(int C[][nCOLUMN], int A[][nCOLUMN], int B[][nCOLUMN])
{
    int i, j, k; 

    for (i = 0; i < nROW; i++)
    {
        for (j = 0; j < nCOLUMN; j++)
        {
            C[i][j] = 0;

            for (k = 0; k < nROW; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    print2DArray(C);
}

void PrintColumnMajorOrder(int M[][nCOLUMN])
{
    int i, j;

    printf("PrintColumnMajorOrder:\n");

    for (i = 0; i < nCOLUMN; i++)
    {
        printf("Column %d: \n", i);

        for (j = 0; j < nROW; j++)
        {
            printf("%d\n", M[j][i]);
        }
    }
}
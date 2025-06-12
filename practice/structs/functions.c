#include "head.h"

void InputFunc1 (cType *ptr)
{
	int j;
	// Struct a
	scanf("%c %d ", &ptr->a.ch, &ptr->a.i);
	// Struct b
	scanf("%f %lf", &ptr->b.f, &ptr->b.d);
	// Array
	
	for (j = 0; j < 5; j++)
	{
		scanf("%d ", &ptr->A[j]);
	}	

}

cType InputFunc2 ()
{
	cType temp;
	
	int j;
	// Struct a
	scanf("%c %d", &temp.a.ch, &temp.a.i);
	// Struct b
	scanf("%f %lf", &temp.b.f, &temp.b.d);
	// Array
	
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &temp.A[j]);
	}	

	return temp;
}

void InputFunc3 (cType C[], int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		InputFunc1(C + j);
	}
}

void OutputFunc1(cType *ptr)
{
	int j;

	printf("%c %d %f %lf\n", (*ptr).a.ch, (*ptr).a.i, (*ptr).b.f, (*ptr).b.d);

	printf("\n{\n");
	for (j = 0; j < 5; j++)
	{
		printf("%d ", (*ptr).A[j]);
	}
	printf("\n}\n");
}

void OutputFunc2(cType *ptr)
{
	int j;

	printf("%c %d %f %lf\n", ptr->a.ch, ptr->a.i, ptr->b.f, ptr->b.d);

	printf("\n{\n");
	for (j = 0; j < 5; j++)
	{
		printf("%d ", ptr->A[j]);
	}
	printf("\n}\n");
}

void OutputFunc3(cType C[], int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		OutputFunc1(&C[j]);
	}
}

void OutputFunc4(cType C[], int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		OutputFunc2(C + j);
	}
}

int Total1(aType A[], int n)
{
	int j;
	int total = 0;

	for (j = 0; j < n; j++)
	{
		total += A[j].i;	
	}

	return total;
}

int Total2(cType c)
{
	int j;
	int total = 0;

	for (j = 0; j < 5; j++)
	{
		total += c.A[j];	
	}

	return total;
}

int Total3(cType C[], int n)
{
	int j;
	int total = 0;

	for (j = 0; j < n; j++)
	{
		total += Total2(C[j]);
	}

	return total;
}

int Minimum(cType c)
{
	int j;
	int minIdx = 0;

	for (j = 0; j < 5; j++)
	{
		if (c.A[j] < c.A[minIdx])
		{
			minIdx = j;
		}
	}

	return minIdx;
}

float fMinimum(bType B[], int n)
{
	int j;
	int minIdx = 0;

	for (j = 0; j < n; j++)
	{
		if (B[j].f < B[minIdx].f)
		{
			minIdx = j;
		}
	}

	return minIdx;
}

void SortFunc1 (aType A[], int n)
{
	int j, k;
	int minIdx;
	int temp;

	for (j = 0; j < n; j++)
	{
		minIdx = j;

		for (k = j + 1; k < n; k++)
		{
			if (A[k].i < A[minIdx].i)
			{
				minIdx = k;
			}	
		}

		if (minIdx != j)
		{
			temp = A[j].i;
			A[j].i = A[minIdx].i;
			A[minIdx].i = temp;
		}
	}
}

void SortFunc2 (bType B[], int n)
{
	int j, k;
	int maxIdx;
	float temp;

	for (j = 0; j < n; j++)
	{
		maxIdx = j;

		for (k = j + 1; k < n; k++)
		{
			if (B[k].f > B[maxIdx].f)
			{
				maxIdx = k;
			}	
		}

		if (maxIdx != j)
		{
			temp = B[j].f;
			B[j].f = B[maxIdx].f;
			B[maxIdx].f = temp;
		}
	}
}

void copyCtype(cType src, cType *dest)
{
	int j;

	dest->a.i = src.a.i;
	dest->a.ch = src.a.ch;
	dest->b.f = src.b.f;
	dest->b.d = src.b.d;

	for (j = 0; j < 5; j++)
	{
		dest->A[j] = src.A[j];
	}
}

void CopyFunc (cType sourceArr[], cType destArr[], int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		copyCtype(sourceArr[j], &destArr[j]);
	}
}

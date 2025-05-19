#include <stdio.h>
#define SIZE (15)

int main()
{

    int A[SIZE];
    int j = 0, flag = 0;
    int k = 0;
    int nNum;
    int nTotal = 0;
    float fAvg = 0;
    int values[SIZE];

    // Input
    printf("Enter 15 positive numbers\n");
  
    do 
    {
        printf("Enter a number: ");
        scanf("%d", &nNum);
        if (nNum > 0)
        {
            A[j] = nNum;
            j++;
        }

        else
        {
            flag = 1;
        }

    } while (j < SIZE && !flag);

    // Print
    printf("The array elements: \n");


    while (k < j)
    {
        printf("%d ", A[k]);
        nTotal += A[k];
        k++;
    }
    
    printf("\n");

    fAvg = nTotal*(1.0) / k;
    printf("Average: %.2f\n", fAvg);

    k = 0;

    for (k = 0; k < SIZE; k++)
    {
        values[k] = 0;
    }

    for (k = 0; k < j; k++)
    {
        values[k] = A[k];
    }

    return 0;
}

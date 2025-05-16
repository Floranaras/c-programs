#include <stdio.h>
#define SIZE (15)

int main()
{

    int A[SIZE];
    int j = 0, flag = 0;
    int k = 0;
    int num;

    // Input
    printf("Enter 15 positive numbers\n");
  
    do 
    {
        printf("Enter value: ");
        scanf("%d", &num);
        if (num > 0)
        {
            A[j] = num;
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
        k++;
    }
    
    printf("\n");

    return 0;
}
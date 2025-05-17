#include <stdio.h>
#define SIZE (15)

void input(int* A, int *j)
{
    int num;
    int flag = 0;

    do
    {
        printf("Enter value: ");
        scanf("%d", &num);
        if (num > 0)
        {
            A[*j] = num;
            j++;
        }

        else
        {
            flag = 1;
        }
    }
    while (*j < SIZE && !flag);
}

void print(int* A, int* j)
{
    int k = 0;

    printf("The array elements: \n");

    while (k < *j)
    {
        printf("%d ", A[k]);
        k++;
    }

    printf("\n");

}

void sort(int* A)
{
    int i, j, temp;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (A[i] < A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main()
{

    int A[SIZE];
    int j = 0;
    int choice;

    printf("=======================\n");
    printf("\tMENU\n");
    printf("=======================\n");

    printf("[1] Enter value/s \n");
    printf("[2] Print values \n");
    printf("[3] Sort values \n");

    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input(A, &j);
        break;
    case 2:
        print(A, &j);
        break;
    case 3:
        sort(A);
        break;
    default:
        printf("Invalid Input\n Please try again\n");
    }

    return 0;
}
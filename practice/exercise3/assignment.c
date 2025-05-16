#include <stdio.h>
#define SIZE (15)

void initArr(int* A)
{
    int j;
    for (j = 0; j < SIZE; j++)
    {
        A[j] = 0;
    }
}

void input(int* A, int *j)
{
    int num;
    int flag = 0;
    
    printf("=======================\n");
    printf("\tINPUT\n"); 
    printf("=======================\n");
    do
    {
        printf("Enter value: ");
        scanf("%d", &num);
        if (num > 0)
        {
            A[*j] = num;
            (*j)++;
        }
        else
        {
            flag = 1;
        }
    } while (*j < SIZE && !flag);
}

void print(int* A)
{
    int k = 0;
    
    printf("=======================\n");
    printf("\tPRINT\n"); 
    printf("=======================\n");
    printf("The array elements: \n");
    while (k < SIZE && A[k] > 0)
    {
        printf("%d ", A[k]);
        k++;
    }
    printf("\n");
}

void sort(int* A, int idx)
{
    int i, j, temp;
    for (i = 0; i < idx - 1; i++)
    {
        for (j = i + 1; j < idx; j++)
        {
            if (A[i] > A[j])  
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("SORTED!!!\n");
}

int main()
{
    int A[SIZE];
    int j = 0;
    char choice;
    int flag = 0;
    
    initArr(A);
    
    do
    {
        printf("=======================\n");
        printf("\tMENU\n");
        printf("=======================\n");
        printf("[1] Enter value/s \n");
        printf("[2] Print values \n");
        printf("[3] Sort values \n");
        printf("[x] Exit\n");
        printf("\nEnter choice: ");
        scanf(" %c", &choice);
        
        switch (choice)
        {
            case '1': input(A, &j); break;
            case '2': print(A); break;
            case '3': sort(A, j); break;
            case 'x': flag = 1; break;
            default: printf("Invalid Input\n Please try again\n");
        }
    } while (!flag);
    
    return 0;
}
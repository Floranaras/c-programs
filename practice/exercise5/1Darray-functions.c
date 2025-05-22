#include <stdio.h>

#define MAX (5)

int isInList(int *list)
{
    int i = 0, flag = 0, key;

    printf("Input key: ");
    scanf("%d", &key);

    while (i < MAX && !flag)
    {
        if (key == list[i])
            flag = 1;
        i++;
    }

    return flag;
}

int getMaxValue(int *list)
{
    int max = list[0];
    int i;

    for (i = 0; i < MAX; i++)
    {
        if (list[i] > max)
            max = list[i];
    }

    return max;
}

void getIdxSwap(int *idx, int *swap)
{
    printf("Input index: ");
    scanf("%d", idx);  
    printf("Enter data: ");
    scanf("%d", swap);
}
void replaceDataAt(int *list)
{
    int idx, swap;

    getIdxSwap(&idx,&swap);
    list[idx] = swap;
}

void printArray(int *list)
{
    int i;

    printf("Values of the Array:\n");

    for (i = 0; i < MAX; i++)
        printf("%d\n", list[i]);
}

void addDataAt(int *list)
{
    int idx, swap, i;

    getIdxSwap(&idx,&swap);

    //Adjust it by one
    for (i = MAX; i > idx; i--)
        list[i] = list[i - 1];

    list[idx] = swap; 
}

void deleteData(int *list)
{
    int idx, i;
    printf("Input index: ");
    scanf("%d", &idx);

    for (i = idx; i > 0; i--)
        list[i] = list[i - 1];

    list[0] = 0;
}

void sortAsc(int *list)
{
    int i, j, temp;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (list[i] < list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

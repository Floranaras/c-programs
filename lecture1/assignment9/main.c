#include <stdio.h>

#define MAX (5)

int find (int *arr, int size, int key)
{
    if (arr[size - 1] == key)
        return size - 1;
    else if (size == 0)
        return -1;
    return find (arr, size - 1, key);
}

int main ()
{
    int j;
    int key;
    int nums[MAX] = {1,2,3,4,5};

    //All Values in the array
    for (j = 0; j < MAX; j++)
    {
        key = nums[j]; 
        printf("%d is found at index %d\n",key, find(nums, MAX,key));
    }

    //Value not in the array
    printf("%d is found at index %d\n",6, find(nums, MAX, 6));

    return 0;
}

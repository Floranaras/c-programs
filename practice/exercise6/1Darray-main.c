#include <stdio.h>
#include "1Darray-functions.c"

int main()
{
    int src[MAX] = {2, 6, 10, 29, 5};
    int dst[MAX] = {3, 6, 11, 17, 2};
    int test[] = {2, 3, 5, 2, 55};

    // isEqual checker
    printf("\nisEqual checker:\n");
    if (isEqual(src, dst, SIZE))
        printf("The arrays are equal\n");
    else 
        printf("The arrays are not equal\n");

    // removeDuplicates checker 
    removeDuplicates(test, SIZE);
    printf("\nremoveDuplicate checker:\n");
    printArr(test, SIZE);

    // addUnique checker
    initArr(src);
    initArr(dst);
    addUnique(src,dst,SIZE);

    printf("\naddUnique checker:\n");
    printf("src Array: ");
    printArr(src, MAX);
    printf("dst Array: ");
    printArr(dst, MAX);
    
    return 0;
}

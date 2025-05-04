#include <stdio.h>
#include "1Darray-functions.c"

int main()
{
    int size = 5;
    int src[] = {2, 6, 10, 29, 5};
    int dst[] = {3, 6, 11, 17, 2};

    // isEqual checker
    if (isEqual(src, dst, size))
        printf("The arrays are equal\n");
    else 
        printf("The arrays are not equal\n");

    //
    
    return 0;
}

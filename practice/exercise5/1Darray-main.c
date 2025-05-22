#include "1Darray-functions.c"

int main()
{
    int list[MAX] = {1, 2, 3, 4, 5};

    //isInList checker
    if (isInList(list) == 1)
        printf("key is found\n");
    else
        printf("key is not found\n");

    //getMaxValue checker
    printf("The highest value is %d\n", getMaxValue(list));

    //replaceDataAt checker
    printArray(list);
    replaceDataAt(list);
    printArray(list);

    //addDataAt checker
    addDataAt(list); 
    printArray(list);
    //deleteData checker
    deleteData(list);
    printArray(list);

    //sortAsc checker
    sortAsc(list);
    printArray(list);

    return 0;
}

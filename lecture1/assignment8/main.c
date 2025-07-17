#include <stdio.h>

#define MAX (3)

int countDigits (int num)
{
    if (num < 10)
        return 1;
    return 1 + countDigits (num / 10);
}

int main ()
{
    int j;
    int numList[MAX] = {8,10,24689753};

    for (j = 0; j < MAX; j++)
    {
        printf("countDigits(%d) returns %d\n", numList[j], 
               countDigits(numList[j]));
    }

    return 0;
}

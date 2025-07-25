#include <stdio.h>

void convert (int *hours, int *minutes)
{
    if (*hours != 0)
    {
        (*hours)--;
        (*minutes) += 60;
        convert(hours, minutes);
    }
}

int main ()
{
    int hours = 3;
    int minutes = 90;

    printf("%d %d\n", hours, minutes);

    convert(&hours, &minutes);

    printf("%d %d\n", hours, minutes);
    return 0;
}

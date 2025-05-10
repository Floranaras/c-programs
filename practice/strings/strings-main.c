#include <stdio.h>
#include <string.h>
#include "strings-function.c"

int main()
{
    char str1[13], str2[13];
    strcpy(str1, "Hello World!");

    char str[21];

    problemOne();

    printf("PrintReverse: ");
    PrintReversed("ABC");

    printf("\nIsPalindrone: %d\n", IsPalindrone(WORD));

    printf("%s\n", str1);
    strcpy(str2, Capitalize(str1));
    printf("%s\n", str2);

   GetPassword(str);



    return 0;
}

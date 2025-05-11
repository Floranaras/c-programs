#include <stdio.h>
#include <string.h>
#include "strings-function.c"

int main()
{
    char str1[13], str2[13], str[21];
    strcpy(str1, "Hello World!"); 
    String10 friends[NUM_FRIENDS] = {"Jack","John", "Jimmy", "James", "George"};
    problemOne();

    printf("PrintReverse: ");
    PrintReversed("ABC");

    printf("\nIsPalindrone: %d\n", IsPalindrone(WORD));

    printf("%s\n", str1);
    strcpy(str2, Capitalize(str1));
    printf("%s\n", str2);

    GetPassword(str);
    SortNicknames(friends, NUM_FRIENDS);

    return 0;
}

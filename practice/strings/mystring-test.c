#include <stdio.h>
#include <string.h>
#define STR "CAR" 

int main() {
    char str1[4] = {'C','A','T'};
    char str2[4] = {'D','O','G'};
    char str10[11] = {'N','E','K','O'};

    printf("\n===STRLEN TEST===\n");
    printf("string.h: %d\n", strlen(STR));
    printf("mystring.c: %d\n", mystrlen(STR));

    printf("\n===STRCPY TEST===\n");
    strcpy(str1, STR);
    printf("string.h: %s\n", str1);
    mystrcpy(str2, str1);
    printf("mystring.c: %s\n",str1);

    printf("\n===STRCAT TEST===\n");
    strcat(str10, STR);
    printf("string.h: %s\n", str10);
    mystrcpy(str10,"NEKO");
    mystrcat(str10, STR);
    printf("mystring.c: %s\n",str10);


    printf("\n===STRCMP TEST===\n");
    printf("string.h: %d\n", strcmp("NEKO", "CAT"));
    printf("mystring.c: %d\n",mystrcmp("NEKO", "CAT"));

    return 0;
}

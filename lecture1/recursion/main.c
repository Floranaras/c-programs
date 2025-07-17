#include <stdio.h>

void foo1()
{
    printf("Hello\n");
    foo1();
}

int main ()
{
    foo1(); 
    return 0;
}

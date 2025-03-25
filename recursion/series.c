#include <stdio.h>

void Series2(int n)
{
    if (n > 0){
        Series2(n-1);
        printf("n = %d\n", n);
    }
}
int main (){
    int n;

    printf("Input n: ");
    scanf("%d",&n);
    Series2(n);
    return 0;
}

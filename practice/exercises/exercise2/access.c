#include <stdio.h>

void functionOne(int num)
{
	num *= 2;
}

void functionTwo(int *num)
{
	*num *= 2;
}


int main()
{
	int x = 5;

	printf("Original Value: %d\n",x);
	functionOne(x);
	printf("Value After functionOne: %d\n",x);
	functionTwo(&x);
	printf("Value After functionTwo: %d\n",x);
	
	return 0;
}

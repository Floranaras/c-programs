#include <stdio.h>

int main()
{
	char ch = 'A';
	int num = 2022;
	float gpe = 4.0;
	double pi = 3.1459;

	printf("%p\n", &ch);
	printf("%p\n", &num);
	printf("%p\n", &gpe);
	printf("%p\n", &pi);

	return 0;
}

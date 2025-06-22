#include "functions.c"

int main ()
{
	int values[SIZE] = {10, 5, 6, 7, 12, 30, 82, 9};

	insertAt(values, 3, 50);
	printArr(values, SIZE);
	insertAt(values, 8, 25);
	printArr(values, SIZE);
	insertAt(values, 0, 8);
	printArr(values, SIZE);

	printf("getCountOf result: ");
	printf("%d\n",getCountOf(values, 82, SIZE));
	return 0;
}

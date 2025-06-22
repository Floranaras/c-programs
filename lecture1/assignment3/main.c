#include "functions.c"

#define SIZE (12)

int main()
{
	int setA[SIZE], setB[SIZE];

	initArr(setA, SIZE); 
	initArr(setB, SIZE); 

	printf("Elements for setA (input 0 to stop):\n");
	inputArr(setA, SIZE);
	printf("Elements for setB (input 0 to stop):\n");
	inputArr(setB, SIZE);

	printf("\ncurrent setA array:");
	printArr(setA, SIZE); 
	printf("\ncurrent setB array:");
	printArr(setB, SIZE); 

	getUnion(setA, setB, SIZE);
	
	printf("\nAfter getUnion setA array:");
	printArr(setA, SIZE); 
	printf("\nAfter getUnion setB array:");
	printArr(setB, SIZE); 


	return 0;
}

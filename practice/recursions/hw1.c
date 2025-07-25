#include <stdio.h>
#include <string.h>

void printRev (int n)
{
	if (n < 10)
		printf ("%d", n);

	else
	{	 
		printf ("%d", n % 10);		
		printRev (n / 10);
	}	
}

int revNum (int n, int rev)
{
	if (n == 0)
		return rev;

	return revNum(n / 10, rev * 10 + n % 10);
}

char* revStr (char *str, int start, int size, char* rev)
{
	rev[start] = str[size - 1];

	if (size - 1 == 0)
		return rev;

	return revStr (str, start + 1, size - 1, rev);
}

int binarySearch (int* numbers, int key, int low, int high)
{
	int mid = low + (high - low) / 2;

	if (low > high)
		return -1;
	else if (numbers[mid] == key)
		return mid;
	else if (numbers[mid] > key)
		return binarySearch(numbers, key, low, mid - 1);

	return binarySearch(numbers, key, mid + 1, high);
}

int main ()
{
	int numbers[5] = {1,2,3,4,5};
	char rev[6];
	char str[6];

	strcpy(str,"hello");
	strcpy(rev,"\0");

	printRev(1234);
	printf("\n");

	printf("%d\n", revNum(1234, 0));

	printf("%s\n", revStr(str, 0, 5, rev));

	printf("%d\n", binarySearch(numbers,4,0,5));

	return 0;
}

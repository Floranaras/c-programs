#include "functions.c"

int main()
{
	string50 strInput;
	string30 strDuplicate;

	string10 words[4] = {"apple", "constant", "banana", "Apple"};
	printf("Your fullname: ");
	scanf("%s", strInput);
	printf("The length of the strings: %d\n", (int) strlen(strInput));
	strcpy(strDuplicate, strInput);
	printf("%s\n", strDuplicate);

	printf("Sorting Array...\n");
	sort(words, 4);
	printf("Sorted Array\n");
	printArr(words, 4);

	return 0;
}

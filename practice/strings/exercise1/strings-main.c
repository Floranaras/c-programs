#include "strings-functions.c"

int main()
{
	String50 firstName, lastName;
	char middleInitial;

	printf("displayReverse: \n");
	displayReverse("ANIMO");

	printf("isPalindrome: \n");
	printf("%d\n",isPalindrome("ANIMO"));
	printf("%d\n",isPalindrome("racecar"));

	printf("getFullName: \n");
	getFullName(firstName, lastName, &middleInitial);
	printf("First Name: %s\n", firstName);
	printf("Last Name: %s\n", lastName);
	printf("Middleinital: %c\n", middleInitial);

	printf("isEqual: \n"); 
	printf("%d\n",isEqual("CAR","NEKO"));
	printf("%d\n",isEqual("CAR","CAR"));

	return 0;
}

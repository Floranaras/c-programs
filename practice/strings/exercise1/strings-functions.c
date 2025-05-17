#include <stdio.h>
#include <string.h>

#define STR10 (11)
#define STR50 (50)

typedef char String10[STR10];
typedef char String50[STR50];

void displayReverse(String10 str)
{
	int j;
	int n = strlen(str);

	for (j = n - 1; j >= 0; j--)
	{
		printf("%c", str[j]);
	}

	printf("\n");

}

int isPalindrome(String10 str)
{
	int j = 0;
	int n = strlen(str);
	int flag = 1;

	while(j < n/2 && flag)
	{
		if (str[j] != str[n - 1 - j])
		{
			flag = 0;
		}
		
		j++;
	}

	return flag;
}

void getFullName(String10 firstName, String10 lastName, char* middleInitial)
{
	String50 fullName;
	int j = 0;
	int k;
	
	strcpy(fullName,"Ranara, Ramil B.");

	// Last Name Loop
	while (fullName[j] != ',')
	{
		lastName[j] = fullName[j];
		j++;
	}

	lastName[j] = '\0';

	// First Name Loop
	k = j + 2;
	j = 0;

	while (fullName[k] != ' ')
	{
		firstName[j] = fullName[k];
		j++;
		k++;
	}

	firstName[j] = '\0';
	k++;

	*middleInitial = fullName[k];
}

int isEqual(char *str1, char *str2)
{
	int j = 0;
	int result = 1;  // Default: equal

	while (str1[j] != '\0' && str2[j] != '\0' && result == 1) 
	{
		if (str1[j] != str2[j]) 
		{
			result = 0;
		}
		
		j++;
	}

	// Check for unequal lengths (only if no mismatch found)
	if (result == 1) 
	{
		if (strlen(str1) != strlen(str2)) 
		{
			result = 0;
		}
	}


	return result;
}

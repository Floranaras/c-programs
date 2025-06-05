#include <stdio.h>
#include <string.h>

typedef char String10[11];

void changePasscode(char* passcode)
{
	int bHasUpper, bHasLower, bHasNum;
	int flag = 1;
	int len, j;
	String10 tempPass;
	String10 input;

	// Input current passcode
	printf("Input current passcode: ");
	scanf("%s", input);

	if (!strcmp(input, passcode))
	{
		do
		{
			printf("Input new passcode: ");
			scanf("%s", tempPass);
			len = strlen(tempPass);

			if (len >= 6 && len <= 10)
			{
				bHasLower = 1;
				bHasUpper = 1;
				bHasNum = 1;
				j = 0;

				while (j < len)
				{
					if (tempPass[j] >= 'a' && tempPass[j] <= 'z') bHasLower = 0;
					if (tempPass[j] >= 'A' && tempPass[j] <= 'Z') bHasUpper = 0;
					if (tempPass[j] >= '0' && tempPass[j] <= '9') bHasNum = 0;
					j++;
				}

				if (!bHasLower && !bHasUpper && !bHasNum)
				{
					flag = 0;
					strcpy(passcode, tempPass);
					printf("Passcode changed successfully!\n");
				}
				else
				{
					printf("Passcode must contain at least one lowercase, one uppercase, and one digit.\n");
				}
			}
			else
			{
				printf("Passcode must be between 6 and 10 characters.\n");
			}

		} while (flag);
	}
	else
	{
		printf("Wrong passcode\n");
	}
}

int main()
{
	String10 passcode;
	strcpy(passcode, "Minecraft");

	changePasscode(passcode);
	return 0;
}

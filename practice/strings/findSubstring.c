#include <stdio.h>
#include <string.h>

#define STR10 (11)
#define MAX (10)
#define KEY "fl"
#define NUM_WORDS (6)
typedef char String10[STR10];

void subString(String10* words, String10* subStr, String10 key, int size, int *count)
{
	int j;
	int k;
	int m;
	int keyLen;
	int wordsLen;
	int match = 1;
	int nextword = 1;

	keyLen = strlen(key);

	for (j = 0; j <	size; j++)
	{
		wordsLen = strlen(words[j]);
		nextword = 1;

		for (k = 0; k < wordsLen && nextword; k++)
		{
			match = 1;

			for (m = 0; m < keyLen && match; m++)
			{
				if (words[j][k+m] != key[m])
				{
					match = 0;
				}
			}

			if (match)
			{
				strcpy(subStr[*count], words[j]);
				(*count)++;
				nextword = 0;
			}
		}
	}
}

int main ()
{
	String10 words[MAX] = {"flower","floor","florante","racecar","car","ant"};
	String10 subStr[STR10];
	int j;
	int count = 0;

	subString(words, subStr, KEY, NUM_WORDS, &count);

	if (!count)
	{
		printf("no matches found\n");
	}

	else 
	{
		for (j = 0; j < count; j++)
		{
			printf("%s ", subStr[j]);
		}
		
		printf("\n");
	}

	return 0;
}

#include <stdio.h>

void getFromFile (FILE* fp, char* ch)
{
	int count = 0;

	while (fscanf(fp,"%c", ch) == 1)
	{
		printf("%c", *ch);
		count++;
	}

	printf("%d", count);
}

void appendData ()
{
	FILE *fp;	
	
	fp = fopen("example.txt", "a");

	if (fp == NULL)
	{
		printf("Error opening file\n");
	}

	else
	{
		fprintf(fp,"hello there");
		fclose(fp);
	}
}
int main ()
{
	FILE *fp;
	char ch;

	fp = fopen("data/readOne.txt","r");
	
	if (fp == NULL)
	{
		printf("File not Found.\n");
	}

	else 
	{
		printf("File Found.\n");	
		printf("Input....\n");
		getFromFile(fp, &ch);
		fclose(fp);
	}

	return 0;
}

#include <stdio.h>

int main ()
{
	int data = 1;

	FILE *fp;
	fp = fopen("sample.dat", "wb");
	fwrite(&data,sizeof(int),1, fp);
	fclose(fp);

	return 0;
}

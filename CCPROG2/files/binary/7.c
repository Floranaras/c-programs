#include <stdio.h>

int main ()
{
	int x;

	FILE *fp;

	fp = fopen("sample.dat", "rb");
	fread(&x, sizeof(int), 1, fp);
	fclose(fp);

	printf("%d\n", x);
	return 0;
}

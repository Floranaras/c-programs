#include <stdio.h>

int main ()
{
	int data = 1;

	FILE *fp;

	char ch = 'A';
	int i = 123;
	float f = 6.78;
	double d = 3.1416;

	fp = fopen("binary.dat", "wb");
	fwrite(&ch,sizeof(char),1, fp);
	fwrite(&i,sizeof(int),1, fp);
	fwrite(&f,sizeof(float),1, fp);
	fwrite(&d,sizeof(double),1, fp);

	fclose(fp);

	return 0;
}

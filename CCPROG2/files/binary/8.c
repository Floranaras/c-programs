#include <stdio.h>

int main ()
{
	char ch;
	int i;
	float f;
	double d;


	FILE *fp;

	fp = fopen("binary.dat", "rb");
	fread(&ch,sizeof(char),1, fp);
	fread(&i,sizeof(int),1, fp);
	fread(&f,sizeof(float),1, fp);
	fread(&d,sizeof(double),1, fp);

	printf("%c\n", ch);
	printf("%d\n", i);
	printf("%f\n", f);
	printf("%lf\n", d);
	
	fclose(fp);

	return 0;
}

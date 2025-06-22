#include <stdio.h>

int main (){

	char ch = 'A';
	int i = 123;
	float f = 4.0;
	double d = 3.1415259;

	FILE *fp;

	fp = fopen("sample.txt", "w");


	fprintf(fp, "%c %d %f %lf" , ch, i, f, d);
	fclose(fp);
	return 0;
}

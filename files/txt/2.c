#include <stdio.h>
#include <stdlib.h>

typedef char str[21];

int main () {

	char ch ;
	int i ;
	float f ;
	double d ;
	str filename;

	FILE *fp;

	fprintf(stdout, "Input filename: ");
	fscanf(stdin, "%s", filename);
		 
	if ((fp = fopen(filename,"r"))== NULL){
		fprintf(stderr, "ERROR: %s does not exist.\n", filename);
		exit (1);
		}

	while ((fscanf(fp, " %c %d %f %lf", &ch, &i, &f, &d)) == 4){
		fprintf(stdout, "%c %d %f %lf \n", ch , i , f, d);
	}

	fclose(fp);
	return 0;
}

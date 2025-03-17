#include <stdio.h>
#include <stdlib.h>

typedef char str[21];

void inputFile(str filename, FILE *fp){

	char ch;
	int i;
	float f;
	double d;
	FILE *outf;


	if ((fp = fopen(filename,"r"))== NULL){
		fprintf(stderr, "ERROR: %s does not exist.\n", filename);
		exit (1);
		}
	
	outf = fopen("numbers.txt", "w");

	while ((fscanf(fp, " %c %d %f %lf", &ch, &i, &f, &d)) == 4){
		fprintf(stdout, "%c %d %f %lf \n", ch , i , f, d);
		fprintf(outf, "%d\n", i);
	}

	fclose(fp);
	fclose(outf);

}
int main () {

	FILE *fp;
	str filename;

	fprintf(stdout, "Input filename: ");
	fscanf(stdin, "%s", filename);

	inputFile(filename,fp);
		 
	return 0;
}

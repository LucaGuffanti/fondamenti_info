#include <stdio.h>

int diff(FILE*, FILE*);

int diff(FILE *fp1, FILE *fp2){
	/*in un file binario leggiamo a byte, quindi usaimo i byte*/
	char read1, read2;

	fread(&read1, sizeof(char), 1, fp1);
	freaf(&read2, sizeof(char), 1, fp2);

	while(!feof(fp1) && !feof(fp2) && read1 == read2){
		fread(&read1, sizeof(char), 1, fp1);
		freaf(&read2, sizeof(char), 1, fp2);
	}
	return !(feof(fp1) && feof(fp2));
}
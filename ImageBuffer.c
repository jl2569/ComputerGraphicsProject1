#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* fh = fopen("filename.ppm","W");
	int c = fgetc(fh);
	if(c != 'P' ){
		fprintf(stderr ,  "Error: This is not a ppm file \n");
	}
	unsigned char gray = 30;
	fprintf(fh,"pbh");
	fprintf(fh, "%d ", gray);
}
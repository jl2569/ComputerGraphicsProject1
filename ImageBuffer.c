#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function was designed to turn p3 files to p6
void ppm6(FILE *input , FILE *output){
	char* find = malloc(10000000);
	int filesize = 10000000;
	char* tok;	
	unsigned char number;
	// cycles through the file getting each line that hold a number value and turns it into binary.
	while(fgets(find , filesize , input) != NULL) {
		tok = strtok(find , " \n");
		while(tok){
			number = (unsigned char)atoi(tok);
			fputc(number , output);
			tok = strtok(NULL , " \n");
		}
	}
}
//This function was designed to turn p6 files to p3
void ppm3(FILE *input , FILE *output){
	char* find = malloc(10000000); 
	int filesize = 10000000;
	unsigned char number;
	unsigned char* buffer = (unsigned char*)find;
	int i;
	// cycles through the file reading every character and turns it into ascii.
	while(fread(buffer , filesize, 1 , input)){
		for (i=0;  i<filesize;  i++){
			number = buffer[i];
			fprintf(output , "%u \n" , number);
		}
	}
}
// This function was designed to just recreate the same file into the out put.
void same(FILE *input , FILE *output){
	char c = fgetc(input);
	int counter  = 1;
	char *com;
	com = (char *)malloc(10000000);
	com[0] = c;
	// cycles through the file getting each character and putting it in to the output file.
	while(1){
		if (feof(input)){
			break;
		}
		else{	
			int c = fgetc(input);		
			com[counter] = c;
			if(c == '\n'){
				counter +=1;
			}
			else{
				counter+=1;
			}
		}
	}
	fputs(com , output);
}

int main(int argc , char *argv[]){
	FILE *fh;
	FILE *fp;
	//checks if the number of arguments need are met
	if(argc == 3){
		fprintf(stderr, "Error: # of Arguments do not match number required.");
	}
	// checks whether or not the input file exists 
	fh = fopen(argv[2],"r");
	if(!fh){
		fprintf(stderr ,"Error: This file will not open \n");
	}
	fp = fopen(argv[3],"w+");
	char c = fgetc(fh);
	int counter  = 1;
	int tracker= 0;
	char *str;
	str = (char *)malloc(100);
	str[0] = c;
	//checks wheather or not the file is a ppm file but not in a good way.
	if(c != 'P' ){
		fprintf(stderr ,"Error: This is not a ppm file! \n");
	}
	//cycles through getting every character for the header but the file must only have one comment 
	// or it will either not get the max color value or get part of the image.
	while(1){
		if (tracker == 4){
			break;
		}
		else{
			int c = fgetc(fh);
			str[counter] = c;
			if(c == '\n'){
				tracker+=1;
				counter+=1;
			}
			else{
				counter+=1;
			}
		}
	}
	// checks whether or not the values in the file need to be changed or not based on the magic number.
	if(strcmp(argv[1],"3")==0){
		if (str[1] == '3'){
			fputs(str,fp);
			same(fh,fp);
		}
		else if (str[1] =='6'){
			str[1] = '3';
			fputs(str,fp);
			ppm3(fh,fp);
		}
		else{
			fprintf(stderr ,"Error: Does not support images not P6 or P3 \n");
		}
	}
	else if(strcmp(argv[1],"6")==0){ 
		if(str[1]== '6'){
			fputs(str,fp);
			same(fh,fp);
		}
		else if(str[1] == '3'){
			str[1] = '6';
			fputs(str,fp);
			ppm6(fh,fp);
		}
	} 
	// error if the file in question is not being changed to a p3 or a p6.
	else{
		fprintf(stderr ,"Error: Does not support images not P6 or P3 \n");
	}
	unsigned char gray = 30;
	fprintf(fh,"pbh");
	fprintf(fh, "%d ", gray);
	fclose(fh);
	fclose(fp);
	return(0);
}
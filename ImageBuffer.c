#include <stdio.h>
#include <stdlib.h>

//void ppm6(input,output){
	
//}

void ppm3(FILE *input ,FILE *output){
	char c = fgetc(input);
	int counter  = 1;
	char *com;
	com = (char *)malloc(100000000);
	com[0] = c;
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
	printf("%s", com);
}

void same(FILE *input ,FILE *output){
	char c = fgetc(input);
	int counter  = 1;
	char *com;
	com = (char *)malloc(100000000);
	com[0] = c;
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
	fputs(com,output);
}

int main(int argc, char *argv[]){
	FILE *fh;
	FILE *fp;
	fh = fopen("title.ppm.ppm","r");
	fp = fopen("file.ppm","w");
	char c = fgetc(fh);
	int counter  = 1;
	int tracker= 0;
	char *str;
	str = (char *)malloc(100);
	str[0] = c;
	
	if(c != 'P' ){
		fprintf(stderr ,"Error: This is not a ppm file! \n");
	}
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
	//printf("%c",str[1]);
	//fputs(str,fp);
	if (str[1] == '3'){
		ppm3(fh,fp);
	}
//	else if(str[1]== '6'){
//		ppm6(fh,fp,c);
//	}
	else{
		fprintf(stderr ,"Error: Does not support images not P6 or P3 \n");
	}
	unsigned char gray = 30;
	fprintf(fh,"pbh");
	fprintf(fh, "%d ", gray);
}
#include <stdio.h>
#include <stdlib.h>

//void ppm6(input,output){
	
//}

//void ppm3(input ,output){
	
//}

int main(int argc, char *argv[]){
	FILE *fh;
	fh = fopen("title.ppm.ppm","r");
	//fp = fopen("file.ppm","w");
	int c = fgetc(fh);
	int counter  = 1;
	int tracker= 0;
	char str[45];
	str[0] = c;
	
	if(c != 'P' ){
		fprintf(stderr ,"Error: This is not a ppm file! \n");
	}
	
	while(1){
		if (tracker == 3){
			break;
		}
		else if(c == "#"){
			while(c!= "\n"){
			  int c = fgetc(fh);
			}
		}
		else{
		int c = fgetc(fh);
		str[counter] = c;
		if(counter == "\n"){
			tracker+=1;
			counter+=1;
		}
		else{
			counter+=1;
		}
		}
	}
	printf("%s",str);	
	//printf("%c", c);
	//while(1){
	//	int c = fgetc(fh);
	//	if(counter == 48){
	//		break;
	//	}
	//	printf("%c", c);
	//	counter +=1;
	//}
	
	unsigned char gray = 30;
	fprintf(fh,"pbh");
	fprintf(fh, "%d ", gray);
}
//Name - Madhur Bajpai
//Reg. No. - 2022CA047

#include<stdio.h>
#include<stdlib.h>
#include "radix_sort.h"
void main(){
	FILE *fptr;
	fptr = fopen("inputFile.txt","w");
	fprintf(fptr,"%d ",200);
	for(int i=200;i>=0;i--){
		fprintf(fptr,"%d ",i);
	}
	fclose(fptr);

}

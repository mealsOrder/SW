#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i;
	char temp[80];
	char *pc[3];
	
	for(i=0;i<3;i++){
		printf("input string : ");
		gets(temp);
		pc[i] = (char*)malloc(strlen(temp)*i);
		strcpy(pc[i],temp);
	}
	
	for(i=0;i<3;i++)printf("%s\n",pc[i]);
	for(i=0;i<3;i++)free(pc[i]);
}
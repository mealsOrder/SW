#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i;
	int sum = 0;
	printf("input people num: ");
	scanf("%d",&n);
	
	int *pi = (int *)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		printf("input %d man age: ",i+1);
		scanf("%d",&pi[i]);
		sum += pi[i];
	}
	
	printf("%.1f\n",(double)sum/n);
	
	free(pi);
}
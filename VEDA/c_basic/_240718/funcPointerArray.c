#include<stdio.h>

int add(int a, int b){
	return a+b;
}
int sub(int a,int b){
	return a-b;
}
int mul(int a, int b){
	return a*b;
}
int max(int a,int b){
	if(a>b) return a;
	return b;
}
// int (*pf)(int,int) x
// ( int (*pf)(int,int) ) x     0  1   2   3   4  
int (*funcarray[5])(int,int) = {0,add,sub,mul,max};
int main(){
	int x,y;
	int r;
	int i;
	printf("0.exit\n1.add\n2.sub\n3.mul\n4.max\ninput num: ");
	scanf("%d",&i);
	if( i == 0) return 0;
	printf("input x,y : ");
	scanf("%d%d",&x,&y);
	
	r = funcarray[i](x,y);
	printf("%d",r);
	return 0;
}
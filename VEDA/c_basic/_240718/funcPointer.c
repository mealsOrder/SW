#include<stdio.h>

int sum(int a, int b){
	return a+b;
}
int mul(int a, int b){
	return a*b;
}
int max(int a,int b){
	if(a>b) return a;
	return b;
}
void func( int(*pf)(int,int) ){
	int a, b;
	int res = 0;
	
	printf("input num: ");
	scanf("%d%d",&a,&b);
	res = pf(a,b);
	printf("ans : %d\n",res);
}


int main(){
	int num;
	printf("input 1 or 2 or 3 : ");
	scanf("%d",&num);
	switch(num){
		case 1:
			func(sum);break;
		case 2:
			func(mul);break;
		case 3:
			func(max);break;
	}
	return 0;
}
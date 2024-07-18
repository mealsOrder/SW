#include<stdio.h>

int main(){
	printf("%d\n",sizeof(void)); // 1;
	
	int a = 10;
	double b = 3.5;
	void *vp;
	
	vp = &a;
	printf("a: %d\n",*(int*)vp);
	printf("a: %d\n",(void*)&a);
	printf("a: %d\n",&a); // ??? why run?
	
	vp = &b;
	printf("a: %.1f\n",*(double*)vp);
	printf("a: %d\n",(void*)&a);
	printf("a: %d\n",&a); // ??
	
	
	return 0;
}

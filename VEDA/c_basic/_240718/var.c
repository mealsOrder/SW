#include<stdio.h>

void func(){
	
	{
		static int li = 2;
		int lni;
		
	}
		
	printf("%d",li); // can't see inner scope

}
int main(){
	
	
	func();
}
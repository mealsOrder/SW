#include<stdio.h>

void arr_print(int *pa,int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",*(pa+i)); // pa[i];
	}
	printf("\n");
	
}

// do not use this code style
void arr2_print(int *pa,int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",*(pa+i) ); // pa[i];
	}
	printf("\n");
	
}

// int a[2][3]; pp = a;
// int[2] a[3]
// int*	  a[3]
// int (*a)[3]
void arr22_print(int (*pp)[3]){
	int i,j;
	//printf("ch");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",pp[i][j]);//pp[i][j]
		}
	}
	printf("\n");
}

void arr3_print(int (*ppp)[3][4]){
	int k,i,j;
	for(k=0;k<2;k++){
		for(i=0;i<3;i++){
			for(j=0;j<4;j++){
				printf("%d ",ppp[k][i][j]);
			}
		}
	}
	printf("\n");
}


// do not use this
void prt_arr2(int **pp){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%d ",pp[i][j]);
		}
	}
	printf("\n");
}

// 1d
void func(int p){
	int i,j;
	for(i=0;i<12;i++)printf("%d ", ((int*)p)[i] );
	// p[i] == *(p+i)
	printf("\n");
}

void func2(int pp[3][4]){
	int i,j;
	printf("%d",pp[0]);
	printf("\n");
}

void my_Print(int p){
	printf("cc");
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			// a[3][4]; p = a;
			// int (*p)[4] ;
			// int (*)[4] pp
			printf("%d ",  ((int (*)[4])p)[i][j] );
		}
		printf("\n");
	}
}


int main(){
	
	int a[5] = {10,1,2,3,4};
	int aa[2][3] = {0,1,2,3,4,5};
	int aaa[2][3][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	int a2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	arr_print(a,sizeof(a)/sizeof(int));
	//arr2_print(aa,sizeof(aa)/sizeof(int));
	arr22_print(aa);
	arr3_print(aaa);
	//prt_arr2(a2); //do not use this style
	func(a2);
	func2(a2);
	my_Print(a2);
	
}
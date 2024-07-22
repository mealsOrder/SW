#include<stdio.h>

void func(int x, int y){
    if(x >= y){
        for(int j=1;j<10;j++){
            for(int i=x; i>=y;i--){
                printf("%d * %d = %2d   ",i,j,i*j);
                //cout << i << " * " << j << " = " << i*j<< "   ";
            }
            printf("\n");
        }
    }
    else{
        for(int j=1;j<10;j++){
            for(int i=x; i<=y;i++){
                printf("%d * %d = %2d   ",i,j,i*j);
                //cout << i << " * " << j << " = " << i*j<< "   ";
            }
            printf("\n");
        }
    }
}

// 2~9
int main(){

    int N,M;
    while(1){
        scanf("%d %d",&N,&M);

        if( N >9 || M >9 || N < 2 ||M <2) printf("INPUT ERROR!\n");
        else{
            func(N,M);
            return 0;
        }
        
    }
    return 0;
}
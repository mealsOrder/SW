#include<stdio.h>

void func(int x, int y){
    if(x >= y){
        for(int i=x; i>=y;i--){
            for(int j=1;j<10;j++){
                printf("%d * %d = %2d   ",i,j,i*j);
                if(j%3==0) printf("\n");
                //cout << i << " * " << j << " = " << i*j<< "   ";
            }
            printf("\n");
        }
    }
    else{
        for(int i=x; i<=y;i++){
            for(int j=1;j<10;j++){
                printf("%d * %d = %2d   ",i,j,i*j);
                if(j%3==0) printf("\n");
                //cout << i << " * " << j << " = " << i*j<< "   ";
            }
            printf("\n");
        }
    }
}

// 2~9
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    
    func(N,M);
            
        
    return 0;
}
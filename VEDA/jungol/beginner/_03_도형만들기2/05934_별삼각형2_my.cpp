#include<stdio.h>
#include<string.h>
const int MX = 5;
int arr[MX][MX];
int N;
int main(){
    
    scanf("%d",&N);

    if(N == 0) printf("INPUT ERROR!");
    else{
        for(int i=0;i<(N+1)/2;i++){
            for(int j=0;j<i;j++){
                printf(" ");
            }
            for(int j=i;j<(N+1)/2;j++){
                printf("*");
            }
            printf("\n");
        }

         for(int i=0;i<(N+1)/2;i++){

            for(int j=0;j<(N+1)/2-1;j++){
                printf(" ");
            }
            for(int j=0;j<i+1;j++){ // 
                printf("*");
            }
            printf("\n");
        }

    }

    return 0;
}
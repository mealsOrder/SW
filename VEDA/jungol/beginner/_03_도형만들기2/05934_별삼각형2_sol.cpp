#include<stdio.h>
#include<string.h>
const int MX = 5;
int arr[MX][MX];
int N;
int main(){
    
    scanf("%d",&N);

    if(N <=0) printf("INPUT ERROR!");
    else{
        for(int j=0; j<(N+1)/2;j++){
            for(int i=0;i<(N+1)/2;i++){
                if((i-j) < 0) printf(" ");
                else printf("*");
            }
            printf("\n");
        }

        for(int j=0;j<N/2;j++){
            for(int i=0;i<N/2;i++){
                printf(" ");
            }
            for(int i=0;i<j+2;i++){
                printf("*");
            }
            printf("\n");
        }

    }

    return 0;
}
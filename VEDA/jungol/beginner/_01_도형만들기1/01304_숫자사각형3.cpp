#include<stdio.h>
const int MX = 101;
int arr[MX][MX];
int main(){
    int N,M;
    scanf("%d",&N);
    
    int cnt = 1;

    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            arr[i][j] +=cnt;
            cnt++;
        }
    }            

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
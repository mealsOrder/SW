#include<stdio.h>
const int MX = 101;
int arr[MX][MX];
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    
    int cnt = 1;

    for(int i=0;i<N;i++){
        if(i%2 == 0){
            for(int j=0;j<M;j++){
                arr[i][j] +=cnt;
                cnt++;
            }
        }
        else{
            for(int j=M-1;j>=0;j--){
                arr[i][j] +=cnt;
                cnt++;
            }
        }
    }            

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
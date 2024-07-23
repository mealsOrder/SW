#include<stdio.h>
const int MX = 101;
int arr[MX][MX];
int main(){
    int N;
    scanf("%d",&N);
    
    int cnt = 65;

    for(int j=N-1;j>=0;j--){
        for(int i=N-1;i>=0;i--){
            if(cnt > 90) cnt-=26;

            arr[i][j]  = cnt;
            cnt++;
        }    
    }            

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
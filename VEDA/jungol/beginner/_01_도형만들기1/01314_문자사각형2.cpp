#include<stdio.h>
const int MX = 101;
int arr[MX][MX];
int main(){
    int N;
    scanf("%d",&N);
    
    int cnt = 65;

    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if(cnt > 90) cnt-=26;
            
            if(j%2 == 0)
                arr[i][j]  = cnt;
            else
                arr[N-i-1][j]  = cnt;
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
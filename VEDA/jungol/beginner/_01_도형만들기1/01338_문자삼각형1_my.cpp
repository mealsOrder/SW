#include<stdio.h>
#include<string.h>
const int MX = 101;
int arr[MX][MX];

int main(){
    int N=0;
    scanf("%d",&N);
    
    int cnt = 65;

    for(int i=0;i<N;i++){
        int idx = i;
        for(int j=N-1;j>=0;j--){
            arr[idx][j] = cnt;
            idx++;
            cnt++;
            if(cnt > 90) cnt-=26;
            if(idx>N-1) break; // idx 값이 N 보다 커질수 있으므로
        }    
    }            
    //memset(arr,' ',MX)
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == 0) printf("  ");
            else printf("%c ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
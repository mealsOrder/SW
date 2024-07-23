#include<stdio.h>
const int MX = 5;
int arr[MX][MX];

void printT(){
    printf("  ");;
}
int main(){
    int N;
    scanf("%d",&N);
    
    int cnt = 65;

    for(int i=0;i<N;i++){
        int idx = i;
        for(int j=N-1;j>=0;j--){
            if(cnt > 90) cnt-=26;
            
            arr[idx][j] = cnt;
            if(idx>N) continue;
            idx++;
            cnt++;
            
        }    
    }            

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == 0) printT();
            else printf("%c ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
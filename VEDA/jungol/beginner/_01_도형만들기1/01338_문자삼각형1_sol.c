#include<stdio.h>
#include<string.h>
const int MX = 5;
int arr[MX][MX];

void printT(){
    printf("  ");;
}
int main(){
    int N;
    scanf("%d",&N);
    
    int cnt=0;

    for(int j=0;j<N;j++){
        for(int i=0;i<N-j;i++){
            arr[j+i][N-(i+1)] = (char)('A'+(cnt++)%('Z'-'A'+1));
        }    
    }            
    memset(arr,' ',MX*MX);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }    
    return 0;
}
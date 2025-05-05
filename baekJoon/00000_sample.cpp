#include<stdio.h>

int s(int n){
    if(n<=1) return n;
    else return s(n-1)+s(n-3);
}

int main(){
    printf("%d",s(7));
    return 0;
}

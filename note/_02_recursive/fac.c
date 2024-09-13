#include "fac.h"

int factorial(int n)
{
    int ans = 1;
    for(int i=n;i>=1;i--){
        ans*=i;
    }
    return ans;
}


int ans = 1;
int g(int n,int a){
    if(a == n+1){
        return ans;
    }
    else{
        ans*=a; 
        g(n,a+1);
    }
}
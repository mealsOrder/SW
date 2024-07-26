#include<iostream>
#include<cstdio>
using namespace std;
int n = 10;

int main(){
    
    int &refN = n;
    int *pN = &refN;

    printf("%p %p %p %p\n",&n,&refN,pN,&pN);


    return 0;
}
#include<iostream>
#include<string>
using namespace std;
// call by value
void swap1(int a,int b){
    int temp = a;
    a = b;
    b= temp;
}

// call by address
void swap2(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// call by reference
void swap3(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 메모리 공간을 사용하지 않고 비트 연산을 두 수를 교환할수 있음!
// 더 찾아보려면 찾아보삼!

// 일반적인 형테의 스왑
void swapB1(int *x,int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

// XOR연산 이용한 swap
void swapB2(int *x,int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

// 더하기 빼기로도 스왑을 할수 있음!
void swapB3(int *x,int *y){
    *x+=*y;
    *y=*x-*y;
    *x-=*y;
}
int main(){
    int n=2,m=9;
    swap1(n,m);
    cout << n << " " << m << '\n';
    swap2(&n,&m);
    cout << n << " " << m << '\n';
    swap3(n,m);
    cout << n << " " << m << '\n';

    int k = 11, g = 19;
    swapB1(&k,&g);    
    cout << k << " " << g << '\n';
    swapB2(&k,&g);    
    cout << k << " " << g << '\n';
    swapB3(&k,&g);    
    cout << k << " " << g << '\n';

    return 0;
}
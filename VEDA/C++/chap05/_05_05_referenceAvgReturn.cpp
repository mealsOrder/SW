#include<iostream>
using namespace std;

bool average(int a[],int size, double& avg)
{
    if(size <= 0) return false;
    int sum = 0;
    for(int i=0;i<size;i++) sum+=a[i];
    avg = (double)sum/size;
    return true;
}

int main()
{
    int x[] = {0,1,2,3,4,5};
    int *px = x;
    double avg;
    // 책 예제1
    if(average(x,6,avg)) cout << "avg = " << avg << '\n';
    else cout << "error!\n";
    // 책 예제2
    if(average(x,-2,avg)) cout << "avg = " << avg << '\n';
    else cout << "error!\n";
    // 포인터 변수로 넘길 경우
    if(average(px,4,avg)) cout << "avg = " << avg << '\n';
    else cout << "error!\n";
    return 0;
}
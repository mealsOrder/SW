#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double a[5];
int main(){

    for(int i=0;i<5;i++) scanf("%lf",&a[i]);
    double *pa = a;

    for(int i=0;i<5;i++) printf("%.1lf ",*(pa+i));
    return 0;
}
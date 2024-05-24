#include<iostream>
#include<cmath>
using namespace std;
int num[6];
int main() {
    
    int res=0;
    for(int i=1;i<=5;i++){
        cin >> num[i];
        res += pow(num[i],2);
    }
    cout << res%10;
    return 0;
}
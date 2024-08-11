#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool com(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a[10] = {0,};
        for(int i=0;i<10;i++){
            cin >> a[i];
        }
        sort(a,a+10,com);
        cout << a[2] << '\n';
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1001;
int arr[MX];

bool func(int n){
    for(int i=1;i<=45;i++){
        for(int j=1;j<=45;j++){
            for(int k=1;k<=45;k++){
                if(arr[i]+arr[j]+arr[k] == n) return true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >>N;

    for(int i=1;i<=45;i++){
        arr[i] = i*(i+1)/2;
    }
    for(int i=0;i<N;i++){
        int a;
        cin >> a;

        cout << func(a) << '\n';
    }
    return 0;
}
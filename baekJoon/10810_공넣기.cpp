#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 102;
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >>N>>M;
    for(int i=1;i<=M;i++){
        int a,b,c;
        cin >> a>>b>>c;
        for(int j=a;j<=b;j++){
            arr[j] = c;
        }
    }
    for(int i=1;i<=N;i++) cout << arr[i] << " ";
    return 0;
}
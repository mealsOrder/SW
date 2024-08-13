#include<iostream>
#include<algorithm>
using namespace std;
const int MX = 10001;
int arr[MX];
int tmp[MX];
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;

    cin >> N >> M;

    for(int i=0;i<N;i++)cin>>arr[i];
    
    sort(arr,arr+N);

    for(int i=0;i<N-1;i++){
        tmp[i] = arr[i+1]-arr[i];
    }
    sort(tmp,tmp+N-1);
    for(int i=0;i<N-M;i++){
        ans += tmp[i];
    }
    cout << ans <<'\n';
    return 0;
}
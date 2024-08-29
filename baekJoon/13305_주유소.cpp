#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 100001;
long long arr[MX];
long long dist[MX];
long long ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<N;i++){
        cin >> dist[i];
    }

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    long long cur = arr[0];
    ans = cur * dist[1];

    for(int i=1;i<N;i++){
        if(cur > arr[i]){
            ans += arr[i]*dist[i+1];
        }
        else{
            ans += cur*dist[i+1];
        }
        cur = arr[i];
        // ans = ans+min(arr[i]*dist[i],arr[i-1]*dist[i]);
    }

    cout << ans;
    return 0;
}
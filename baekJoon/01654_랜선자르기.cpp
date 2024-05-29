#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 10001;
long long line[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K,N;
    cin >>K>>N;
    for(int i=0;i<K;i++)cin >> line[i];
    sort(line,line+K);
    long long left = 1;
    long long right = line[K-1];
    long long ans = 0;

    while(left<=right){
        int cnt = 0;
        long long mid = (left+right)/2;
        for(int i=0;i<K;i++) cnt += line[i]/mid;

        if(cnt >= N) {
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }
    cout << ans;
    return 0;
}
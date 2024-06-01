#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

const int MX = 30;
int arr[MX];
int N,S;
int cnt;
void back(int cur,int sum){
    if(cur == N){
        if(sum == S) cnt++;
        return;
    }
    back(cur+1,sum);
    back(cur+1,sum+arr[cur]);
}
int main() {
    cin >> N>>S;
    for(int i=0;i<N;i++)cin >> arr[i];

    back(0,0);
    if(S==0) cnt--;
    cout << cnt;
    return 0;
}
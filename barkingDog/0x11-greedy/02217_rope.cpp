#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 100001;
int rope[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> rope[i];
    }
    int ans = 0;
    sort(rope,rope+N);
    for(int i=0;i<N;i++){
        ans = max( ans, (N-i)*rope[i] );
    }
    cout << ans;
    return  0;
}
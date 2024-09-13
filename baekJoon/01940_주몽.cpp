#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MX = 15001;
int a[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M,cnt=0;
    cin >> N>>M;

    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(a[i]+a[j] == M) cnt++;
        }
    }
    cout << cnt/2 << '\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int N;
    cin >> N;
    // 이런거 빼먹지 말자
    // 잘 적어놓고 구현할때 빼먹어서 틀리네...
    if(N == 0){ 
        cout << 0;
        return 0;
    }
    vector<int>v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    int peoCnt = round((double)N*0.15);
    sort(v.begin(),v.end());
    int sum=0;

    for(int i=0+peoCnt;i<N-peoCnt;i++){
        sum += v[i];
    }

    int ans = round((double)sum/(double)(N-(2*peoCnt)));

    cout << ans;
	return 0;
}

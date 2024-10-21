#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 501;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int H,W;
    cin >> H >> W;

    vector<int>v(W,0);
    for(int i=0;i<W;i++)cin>>v[i];

    int ans = 0;
    // 양 끝 제외
    for(int i=1;i<v.size()-1;i++){
        int lef = *max_element(v.begin(),v.begin()+i);
        int rig = *max_element(v.begin()+i+1,v.end());
        int dif = min(lef,rig) - v[i];
        if(dif >=0) ans += dif;
    }
    cout << ans;
	return 0;
}
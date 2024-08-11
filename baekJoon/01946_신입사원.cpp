#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        vector<pair<int,int>>v; // 아... 케이스 문제에서 초기화;; ㅋㅋ
        int N,ans = 1;// 1등
        cin >> N;

        for(int i=0;i<N;i++){
            int a,b;
            cin >> a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        
        int idx = 0;
        for(int i=1;i<N;i++){
            if(v[i].second < v[idx].second){
                idx=i;
                ans++;
            } 
        }
        cout << ans << '\n';        
    }
    return 0;
}
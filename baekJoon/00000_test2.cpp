#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MX = 5;
int N,K;
vector<pair<int,int>>v;
vector<int>ans;
vector<int>d;
bool vis[MX];
void back(int x){
    if(x == K){
        ans.clear();
        for(int i=0;i<N;i++){
            if(!vis[i])continue;
            for(int j=0;j<N;j++){
                if(!vis[j]){
                    int dis = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
                    ans.push_back(dis);
                }
            }
        }
        sort(ans.begin(),ans.end());
        d.push_back(ans[0]);

        
        return;
    }
    else{
        for(int i=0;i<N;i++){
            if(!vis[i]){
                vis[i] = true;
                back(x+1);
                vis[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    back(0);

    sort(d.begin(),d.end());
    cout << d[0];    
    return 0;
}
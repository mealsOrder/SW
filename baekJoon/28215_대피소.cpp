#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MX = 51;
int N,K;
vector<pair<int,int>>v;
vector<vector<int>>arr;
int ans = 1e9;
int dist[MX][MX];
bool vis[MX];
int cal(pair<int,int>a, pair<int,int>b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void back(int x,int idx){
    if(x == K){
        vector<int>tmp;
        for(int i=0;i<N;i++){
            if(vis[i])tmp.push_back(i);
            arr.push_back(tmp);
            return;
        }
    }
    else{
        for(int i=idx;i<N;i++){
            if(!vis[i]){
                vis[i] = true;
                back(x+1,i);
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

    back(0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j] = cal(v[i],v[j]);
        }
    }

    for(int k=0;k<arr.size();k++){
        int big=0;
        for(int i=0;i<N;i++){
            int small = 1e9;
            fill(vis,vis+N,0);
            for(int j=0;j<arr[k].size();j++)vis[arr[k][j]] = true;
            for(int j=0;j<arr[k].size();j++){
                if(!vis[arr[k][j]]) small = min(small,dist[i][arr[k][j]]);
            }
            if(small != 1e9) big = max(small,big);
        }
        ans = min(ans,big);
    }
    cout << ans;
    return 0;
}
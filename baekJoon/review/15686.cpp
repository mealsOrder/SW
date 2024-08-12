#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 51;
const int INF = INT_MAX;
int map[MX][MX];
int N,M;
int ans = INF;

vector<pair<int,int>>h;
vector<pair<int,int>>c;
vector<pair<int,int>>t;

int findDist(){
    int res = 0;
    for(int i=0;i<h.size();i++){
        int dist1 = INF;
        for(int j=0;j<t.size();j++){
            int dist2 = abs(h[i].first - t[j].first)+abs(h[i].second-t[j].second);
            dist1 = min(dist1,dist2);
        }
        res+=dist1;
    }
    return res;
}
void back(int x, int cur){
    if(x == M){
        for(int i=0;i<M;i++){
            ans = min(ans,findDist());
        }
        return;
    }
    else{
        for(int i=cur;i<c.size();i++){
            int nx = c[i].first;
            int ny = c[i].second;
            t.push_back({nx,ny});
            back(x+1,i+1);
            t.pop_back();

        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                h.push_back({i,j});
            }
            else if(map[i][j] == 2){
                c.push_back({i,j});
            }
        }
    }
    back(0,0);
    cout << ans << '\n';
    return  0;
}
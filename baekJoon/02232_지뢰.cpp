#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 50001;
int map[MX];
bool vis[MX];
int dx[] = {-1,1};
int cnt;
vector<pair<int,int>>v; // 값, 인덱스
vector<int>res;
int N;
void BFS(int x){
    queue<int>q;
    if(vis[x]) return;
    vis[x] = true;
    q.push(x);
    cnt++;
    while(!q.empty()){
        int curX = q.front();
        if(cnt == N)return;
        q.pop();

        for(int i=0;i<2;i++){
            int nx = curX+dx[i];

            if(nx>=0&&nx<N&&!vis[nx]&& map[curX] > map[nx]){
                cnt++;
                vis[nx]=true;
                q.push(nx);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> map[i];
        v.push_back({map[i],i});
    }
    sort(v.begin(),v.end(),greater<>());

    for(int i=0;i<N;i++){
        int idx= v[i].second;
        if(!vis[idx]){
            BFS(idx);
            res.push_back(idx);
        }
    }
    
    sort(res.begin(),res.end());

    for(int a : res) cout << a +1 << '\n';
    return 0;
}

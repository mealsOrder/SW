#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 100001;
int N,K;
bool vis[MX];
int ans,cnt;    // 최단 시간,방법 가짓수
void BFS(){
    queue<pair<int,int>>q; // {위치,시간}
    q.push({N,0});

    while(!q.empty()){
        int curX = q.front().first;
        int curT = q.front().second;
        q.pop();
        
        vis[curX] = true; // 큐에서 꺼낼때 방문처리 ** 여기가 핵심

        if(curX == K){
            if(cnt == 0){
                ans = curT;
                cnt = 1;
            }
            else if(curT == ans){
                cnt++;
            }
            continue;
        }

        for(int nx : {curX-1,curX+1,curX*2}){
            if(nx<0 || nx>=MX)continue;
            if(!vis[nx]){
                q.push({nx,curT+1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    if(N == K){
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }
    BFS();

    cout << ans << '\n' << cnt << '\n';
    return 0;
}

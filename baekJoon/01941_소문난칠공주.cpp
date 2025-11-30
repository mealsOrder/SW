#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

string a[5];
bool vis[5][5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool chk[25];
int ans;

bool BFS(int idx){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>>q;
    int cnt = 1;
    vis[idx/5][idx%5] = true;
    q.push({idx/5,idx%5});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        if(cnt == 7) return true;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0&&nx<5&&ny>=0&&ny<5 && chk[nx*5+ny] && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=true;
                cnt++;
            }
        }
    }
    return false;
}


void DFS(int cnt,int depth, int sCnt){
    if(cnt == 7){
        if(sCnt>=4){
            if( BFS(depth)) ans++;
        }
        return;
    }
    for(int i=depth;i<25;i++){
        if(chk[i])continue;
        int k=0;
        if(a[i/5][i%5] == 'S')k=1;
        chk[i] = true;

        DFS(cnt+1,i,sCnt+k);
        chk[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0;i<5;i++)cin >> a[i];

    DFS(0,0,0);

    cout << ans << '\n';

    return 0;
}

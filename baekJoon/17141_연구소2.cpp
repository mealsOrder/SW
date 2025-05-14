#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 50;
int map[MX][MX];
int clo[MX][MX];
bool vis[MX][MX];
int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};

int N, M, res = INT_MAX;
vector<pair<int,int>> virus; // 바이러스 후보 위치
vector<pair<int,int>> active; // 선택된 활성 바이러스

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            clo[i][j] = map[i][j];
            vis[i][j] = false;
        }
    }
}

int BFS(){
    init();
    queue<pair<int,int>> q;

    for(int k=0;k<active.size();k++){
        int x = active[k].first;
        int y = active[k].second;
        q.push({x,y});
        vis[x][y] = true;
    }

    int time = 0;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front().first; 
            int y = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx>=0 && ny>=0 && nx<N && ny<N && !vis[nx][ny] && clo[nx][ny] != 1){
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        time++;
    }

    // 모든 빈 칸이 퍼졌는지 확인
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(clo[i][j] == 0 && !vis[i][j]) return -1; // 못 퍼진 곳 있음
        }
    }

    return time - 1; // 마지막 1초는 의미 없음
}

void back(int x, int start){
    if(x == M){
        int t = BFS();
        if(t != -1) res = min(res, t);
        return;
    }

    for(int i=start; i<virus.size(); i++){
        active.push_back(virus[i]);
        back(x+1, i+1);
        active.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                virus.push_back({i, j});
                map[i][j] = 0; // 바이러스는 빈 칸처럼 취급
            }
        }
    }

    back(0, 0);
    cout << (res == INT_MAX ? -1 : res) << '\n';
    return 0;
}

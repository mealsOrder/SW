#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
// 4시
const int MX = 26;
int map[MX][MX];
bool visited[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N;
queue<pair<int,int>>q;
vector<int>v;
void BFS(int x,int y, int& cnt){
    visited[x][y]=true;
    q.push({x,y});
    cnt++;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[nx][ny]&&map[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]&&!visited[i][j]){
                int count = 0;
                BFS(i,j,count);
                v.push_back(count);
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int e:v) cout << e << '\n';
    return 0;
}
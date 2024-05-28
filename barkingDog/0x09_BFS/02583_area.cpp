#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int MX = 101;
int map[MX][MX];
bool visited[MX][MX];
int M,N,K;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int>v;
queue<pair<int,int>>q;
void BFS(int x,int y,int & cnt){
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

            if(nx>=0&&nx<M&&ny>=0&&ny<N&&!map[nx][ny]&&!visited[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>M>>N>>K;
    for(int t=0;t<K;t++){
        int a,b,c,d;
        cin >> a>>b>>c>>d;
        for(int i=a;i<c;i++){
            for(int j=b;j<d;j++){
                map[j][i] = 1;
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && !map[i][j]){
                int count = 0;
                BFS(i,j,count);
                v.push_back(count);
            }
            //cout << map[i][j]<< " ";
        }
        //cout << '\n'    ;
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int e:v) cout << e << " ";
    return 0;
}
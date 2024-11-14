#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 1001;
int N,ans,cnt,curNum, ansNum;
int map[MX][MX];
bool vis[MX][MX];
vector<pair<int,int>>v;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;  // first가 같을 때 second 기준 오름차순
    }
    return a.first > b.first;  // first 기준 내림차순
}
void BFS(int x,int y){
    queue<pair<int,int>>q;
    memset(vis,0,sizeof(vis));
    vis[x][y] = 1;
    cnt++;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<N && !vis[nx][ny]){
                if(map[nx][ny] == (map[curx][cury] + 1)){
                    vis[nx][ny] = 1;
                    cnt++;
                    q.push({nx,ny});
                }
            }
        }
    }
    v.push_back({cnt,curNum});
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        cin >> N;  
        memset(map,0,sizeof(map));
        v.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> map[i][j];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!vis[i][j]){
                    cnt = 0;
                    curNum = map[i][j];
                    
                    BFS(i,j);
                    if(ans < cnt){
                        ans = cnt;
                        if(ansNum > curNum){
                            ansNum = curNum;
                        }
                    }
                }
            }
        }
        sort(v.begin(),v.end(),cmp);
        cout << '#' << t << ' ' << v[0].second << ' ' << v[0].first << '\n';
    }
		

    return 0;
}
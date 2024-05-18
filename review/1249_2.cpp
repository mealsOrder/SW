#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

const int MAX = 101;
const int INF = 987987987; 
int map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int N;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int BFS(int x,int y){
	queue<pair<int,int>>q;
	dist[x][y] = 0;
	q.push({x,y});
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<N){
				
				if(dist[nx][ny] > dist[curX][curY]+map[nx][ny]){
					dist[nx][ny] = dist[curX][curY]+map[nx][ny];

					q.push({nx,ny});
				}
				
			}
			
		}
		
	}
	
	return dist[N-1][N-1];
}

int main(){
	
	int T;
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		memset(dist,INF,sizeof(dist));
		memset(map,0,sizeof(map));
		
		cin >> N;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%1d",&map[i][j]);
			}
		}
		
		int ans = BFS(0,0);
		
		cout << "#" << t << " " << ans << endl;
	}
	
	return 0;
}
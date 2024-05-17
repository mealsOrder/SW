#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 101;

int map[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int,int>>q;
int N,M;
int dist[MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int BFS(int x, int y){
	visited[x][y] = true;		
	dist[x][y] = 1;
	q.push({x,y});
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		
		if(curX == N-1 && curY ==M-1) return dist[N-1][M-1];
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]&&!visited[nx][ny]){
				visited[nx][ny] = true;
				dist[nx][ny] = dist[curX][curY]+1;
				q.push({nx,ny});
			}
			
		}
			
	}
	
	return -1;
}

int main(){
	
	
	cin >> N>>M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	int ans = BFS(0,0);
	
	cout << ans << endl;
	
	
	
	
	return 0;
}
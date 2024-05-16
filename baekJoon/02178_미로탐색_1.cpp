#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 101;

int map[MAX][MAX];

int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>>q;
int dist[MAX][MAX];
bool visited[MAX][MAX];
int BFS(int x,int y){
	q.push({x,y});
	visited[x][y] = true;
	dist[x][y] = 1;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		if(cx == N-1 && cy == M-1) return dist[N-1][M-1];
		
		for(int i=0;i<4;i++){
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]&&!visited[nx][ny]){
				dist[nx][ny] = dist[cx][cy]+1;
				q.push({nx,ny});
				visited[nx][ny]=true;
			}
			
		}
	}
	
	return -1;
}


int main(){
	
	cin >>N>>M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	int ans = BFS(0,0);
	
	cout << ans << endl;
	
	return 0;
}
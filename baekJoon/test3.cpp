#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 101;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

queue<pair<int,int>> q;
int N,M;

int BFS(int a,int b){
	q.push({a,b});
	dist[a][b]=1;
	visited[a][b] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(x==N && y==M) return dist[N][M];
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0 && nx<N && ny>=0 &&ny<M && map[nx][ny]==1 &&!visited[nx][ny] ){
				dist[nx][ny] = dist[x][y]+1;
				q.push({nx,ny});
				visited[nx][ny] = true;
			}
			
		}
		
	}
	
	
	return -1;
	
}

int main(){
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
    
	int ans = BFS(0,0);
	
	cout << ans << endl;
	

	return 0;
}
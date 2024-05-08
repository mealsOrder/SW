#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;


const int MAX = 1001;

int N,M;
int dx[4] = {0,0,1,-1 };
int dy[4] = {1,-1,0,0 };

int map[MAX][MAX];
int dist[MAX][MAX][2];

queue<pair<pair<int,int>,int>>q;

int BFS(){
	q.push({{N-1,0},0});
	dist[N-1][0][0] = 0;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		
		if(x == 0 && y == M-1) return dist[x][y][wall];
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<M){
				if(map[nx][ny]==0 && dist[nx][ny][wall] == 0){
					q.push({{nx,ny},wall});
					dist[nx][ny][wall] = dist[x][y][wall]+1;
				}
				else if(map[nx][ny]==1 && wall==0 && dist[nx][ny][1]==0){
					q.push({{nx,ny},1});
					dist[nx][ny][1] = dist[x][y][0]+1;
				}
			}
				
		}
		
	}
	return -1;
}

int main(){
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			dist[i][j][0]=dist[i][j][1]=0;
		}
	}
	
	int res = BFS();
	
	cout << res << endl;
	
	
	return 0;
}
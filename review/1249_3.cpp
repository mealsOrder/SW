#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

const int MAX = 101;
const int INF = INT_MAX;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void init(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			map[i][j]=0;
			visited[i][j]=false;
			dist[i][j]=INF;
		}
	}
}

int BFS(int x,int y){
	queue<pair<int,int>>q;
	dist[x][y] = 0;
	q.push({x,y});
	
	while(!q.empty()){
		int curX=q.front().first;
		int curY=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
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
		init();
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
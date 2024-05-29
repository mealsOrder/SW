#include<iostream>
#include<queue>

using namespace std;

const int MX = 1001;
int map[MX][MX];
bool visited[MX][MX];
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
queue<pair<int,int>>q;

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dist[i][j] = -1;
		}
	}
}
void BFS(int x,int y){
	visited[x][y] = true;
	dist[x][y] = 0;
	q.push({x,y});

	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];

			if(nx>=0&&nx<N&&ny>=0&ny<M&&!visited[nx][ny]&&map[nx][ny]>0){
				visited[nx][ny] = true;
				dist[nx][ny] = dist[curX][curY]+1;
				q.push({nx,ny});
			}
		}
	}

}
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >>N>>M;
	init();
	int si,sj;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			if( map[i][j] == 2){
				si=i;
				sj=j;
			}
			if(map[i][j] == 0){
				dist[i][j] = 0;
			}
		}
	}
	
	BFS(si,sj);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
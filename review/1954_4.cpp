#include<iostream>
#include<cstring>

using namespace std;

// solving Time : 20 min
// control
const int MAX = 11;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int N;

void DFS(int x,int y, int cnt, int dir){
	visited[x][y]=true;
	map[x][y] = cnt+1;
	
	if(cnt == N*N) return;
	
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	
	if(nx<0||nx>=N||ny<0||ny>=N|| map[nx][ny] ){
		dir=(dir+1)%4;
		nx = x+dx[dir];
		ny = y+dy[dir];
	}
	
	if(!visited[nx][ny]){
		DFS(nx,ny,cnt+1,dir);
	}
	
}

int main(){
	
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		
		cin >> N;
		
			
		DFS(0,0,0,0);
		
		cout << "#" << t << endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << map[i][j]<<" ";
			}
			cout << endl;
		}		
	}
	
	return 0;
}
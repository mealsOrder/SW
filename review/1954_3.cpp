#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 12;
int map[MAX][MAX];
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			map[i][j] = 0;
		}
	}
}

void DFS(int x,int y,int cnt, int dir){
	if(cnt == N*N) return;
	
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	
	if(nx<0 || nx>=N || ny<0 || ny>=N || map[nx][ny] ){
		dir = (dir+1)%4;
		nx = x+dx[dir];
		ny = y+dy[dir];
	}
	
	map[nx][ny] = cnt+1;
	
	DFS(nx,ny,cnt+1,dir);
}

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		init();
		cin >> N;
		
		// init !!
		map[0][0] = 1;
		DFS(0,0,1,0);

		cout << "#" << t << endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// solving time : 31 min 

int map[11][11];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int T,N;

void init(){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			map[i][j] = 0;
		}
	}
	
}

void DFS(int x, int y, int cnt, int dir){
	
	// (x,y) init
	int nx=x+dx[dir];
	int ny=y+dy[dir];
	
	//Exit condition
	if(cnt == N*N) return;
	
	// over condition
	if(nx<0||nx>=N||ny<0||ny>=N||map[nx][ny]>0){
		dir=(dir+1)%4;
		nx=x+dx[dir];
		ny=y+dy[dir];
	}
	
	map[nx][ny] = cnt+1;
	DFS(nx,ny,cnt+1,dir);
	
}

int main(){
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> N;
		
		
		init();
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
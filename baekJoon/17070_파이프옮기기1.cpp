#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 17;
int map[MAX][MAX];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};

int N,cnt=0;

void DFS(int x,int y,int dir){
	if(x==N && y == N){
		cnt++;
		return;
	}
	
	for(int i=0;i<3;i++){
		
		
		if((dir==0 && i==1) || (dir==1 && i==0)) continue;
		
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx<1||nx>N||ny<1||ny>N||map[nx][ny] ) continue;
		
		if( i==2 && (map[x][y+1] || map[x+1][y]) ) continue;
		
		DFS(nx,ny,i);
		
	}
}

int main(){
		
	
	cin >> N;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> map[i][j];
		}
	}
	
	DFS(1,2,0);
	
	cout << cnt << endl;
	
	
	
	return 0;
}
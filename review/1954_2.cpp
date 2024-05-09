#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 11;

// retry pls...

int arr[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N;

void DFS(int x,int y,int cnt,int dir){
	
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	
	if(cnt == N*N) return;
	
	if(nx<0||nx>=N||ny<0||ny>=N||arr[nx][ny]){
		dir = (dir+1)%4;
		nx = x+dx[dir];
		ny = y+dy[dir];
	}
	
	arr[nx][ny] = cnt+1;
	
	DFS(nx,ny,cnt+1,dir);
	
}

void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			arr[i][j]=0;
		}
	}	
}


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		cin >> N;
		init();
		arr[0][0] = 1;
		DFS(0,0,1,0);
		cout << "#" << t << endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	

	return 0;
}
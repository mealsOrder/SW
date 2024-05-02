#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int arr[11][11];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int T,N;

void dfs(int x,int y,int cnt,int dir){
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	
	if(cnt == N*N) return;
	
	if(nx<0||nx>=N||ny<0||ny>=N||arr[nx][ny]>0){
		
		dir = (dir+1)%4;
		nx = x + dx[dir];
		ny = y + dy[dir];
		
	}
	
	arr[nx][ny] = cnt+1;
	
	dfs(nx,ny,cnt+1,dir);
}

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=0;
        }
    }
}

int main(){
	
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		cin >> N;
		
		init();
		arr[0][0] = 1;
		dfs(0,0,1,0);
		
		cout << "#" << t << endl;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cout << arr[i][j] << " ";
	        }
	        cout << endl;
	    }
	}
	


}
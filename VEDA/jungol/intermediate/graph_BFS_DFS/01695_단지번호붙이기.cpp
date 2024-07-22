#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MX = 26;
int map[MX][MX];
int vis[MX][MX];

vector<int>houses;
int N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void DFS(int x,int y, int& cnt){
	if(vis[x][y])return;
	
	vis[x][y] = true;
	cnt++;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]&&map[nx][ny]){
			DFS(nx,ny,cnt);	
		}
		
	}
	
}


int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
	cin >> N;
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			if(!vis[i][j] && map[i][j]){
				int count = 0;
				DFS(i,j,count);
				houses.push_back(count);
			}
			
		}
		
	}
	sort(houses.begin(),houses.end());
	
	cout << houses.size()<< endl;
	for(int elem:houses)cout << elem << endl;
	
	
	
	return 0;
}
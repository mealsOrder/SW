#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//solving time : 20 min

const int MAX = 26;
int map[MAX][MAX];
int visited[MAX][MAX];
vector<int>houses;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int N;

void DFS(int x,int y,int& cnt){
	
	if(visited[x][y])return;
	
	visited[x][y] = true;
	cnt++;
	
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0 && nx<N && ny>=0 && ny<N && map[nx][ny] && !visited[nx][ny]){
			DFS(nx,ny,cnt);
		}
		
	}	
	
	
}

int main(){
	
	cin >> N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
    
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j] && !visited[i][j]){
				int count = 0;
				DFS(i,j,count);
				houses.push_back(count);
			}
			
		}
	}
	
	sort(houses.begin(),houses.end());
	cout << houses.size() << endl;
	for(int elem:houses){
		cout << elem << endl;
	}
	
	return 0;
}
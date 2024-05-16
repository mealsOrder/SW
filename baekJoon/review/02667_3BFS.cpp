#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 26;

int map[MAX][MAX];
bool visited[MAX][MAX];
int N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>>q;
vector<int>houses;

void BFS(int x,int y){
	visited[x][y] = true;
	q.push({x,y});
	int cnt = 0;
	cnt++;
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]&&!visited[nx][ny]){
				q.push({nx,ny});
				visited[nx][ny] = true;
				cnt++;
			}
			
		}
	}
	houses.push_back(cnt);
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
				
				BFS(i,j);
				
			}
		}
	}	
	
	sort(houses.begin(),houses.end());
	
	cout << houses.size()<< endl;
	for(int elem:houses){
		cout << elem << endl;
	}
		
	
	
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 51;

int map[MAX][MAX];
bool visited[MAX][MAX];
int M,N,K;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int>v;
queue<pair<int,int>>q;

void BFS(int x,int y){
	visited[x][y] = true;
	q.push({x,y});
	int cnt = 1;
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[nx][ny]&&!visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx,ny});
				cnt++;
			}
			
		}
		
	}
	v.push_back(cnt);
}


int main(){
    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> M>>N>>K;
		memset(map,0,sizeof(map));
		memset(visited,false,sizeof(visited));
		v.clear();
		while(!q.empty())q.pop();
		
		for(int i=0;i<K;i++){
			int a,b;//x //y
			cin >> a>>b;
			map[a][b]=1;
		}
		
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(map[i][j] && !visited[i][j]){
					BFS(i,j);
				}
			}
		}
		
		cout << v.size()<<endl;
		
	}
	

	return 0;
}
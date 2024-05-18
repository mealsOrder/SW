#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 101;

int map[MAX][MAX]; 
bool visited[MAX][MAX];
int si,sj,ei,ej; // strat, end
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int BFS(int x,int y){
	queue<pair<int,int>>q;
	visited[x][y] = true;
	q.push({x,y});
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		
		if(curX == ei && curY == ej) return 1;
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
			if(nx>=0&&nx<100&&ny>=0&&ny<100&&!visited[nx][ny]&&!map[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx,ny});
			}
			
		}
		
	}
	
	return 0;
}

int main(){
	
	
	for(int t=1;t<=10;t++){
		int T;
		cin >> T;
		
		memset(map,0,sizeof(map));
		memset(visited,false,sizeof(visited));
		
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				scanf("%1d",&map[i][j]);
				
				if(map[i][j] == 2){
					si=i;
					sj=j;
					map[i][j] = 0;
				}
				else if(map[i][j] == 3){
					ei=i;
					ej=j;
					map[i][j]=0;
				}
				
			}
		}
		
		int ans = BFS(si,sj);
		
		cout << "#" << t << " " << ans << '\n';
		
			
	}	
	
	return 0;
}
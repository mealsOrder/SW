#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MAX = 101;
const int INF = INT_MAX;
int map[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;

queue<pair<int,int>>q;

int BFS(){
	
	dist[0][0] = 0;
	
	q.push({0,0});
	
	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = curX+dx[i];
			int ny = curY+dy[i];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N){
				
				if(dist[nx][ny] > dist[curX][curY] + map[nx][ny]){
					dist[nx][ny] = dist[curX][curY] + map[nx][ny];
					
					q.push({nx,ny});
					
				}
			}
			
		}
	}
	
	return dist[N-1][N-1];
}

int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> N;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%1d",&map[i][j]);
				dist[i][j] = INF;				
			}
		}
		
				
		int ans = BFS();
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}
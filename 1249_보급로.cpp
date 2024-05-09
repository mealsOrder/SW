#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int INF = 987654321;
const int MAX = 101;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int map[MAX][MAX];
int dist[MAX][MAX];

int N;

queue<pair<int,int>>q;


int BFS(){
	q.push({0,0});
	dist[0][0] = map[0][0];
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N){
				if(dist[nx][ny]>map[nx][ny]+dist[x][y]){
					dist[nx][ny] = map[nx][ny] + dist[x][y];
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
				dist[i][j]=INF;
			}
		}		
		
		int ans = BFS();

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}
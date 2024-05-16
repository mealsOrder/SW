#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 26; // 격자의 최대 크기 정의

int map[MAX][MAX]; // 격자 정보를 저장할 2차원 배열
bool visited[MAX][MAX]; // 격자 방문 정보를 저장할 2차원 배열
int N; // 격자의 크기
int dx[4] = {0,0,1,-1}; // x 좌표 변화를 나타내는 배열
int dy[4] = {1,-1,0,0}; // y 좌표 변화를 나타내는 배열

queue<pair<int,int>>q; // BFS를 위한 큐
vector<int>houses; // 단지 내 집의 수를 저장할 벡터

void BFS(int x,int y){ // BFS 함수
	visited[x][y] = true; // 현재 격자를 방문했다고 표시
	q.push({x,y}); // 큐에 현재 격자 좌표 넣기
	int cnt = 0; 
	cnt++; // 단지 내 집의 수 증가

	while(!q.empty()){ // 큐가 빌 때까지 반복
		int curX = q.front().first; // 현재 x 좌표
		int curY = q.front().second; // 현재 y 좌표
		q.pop(); // 큐에서 현재 좌표 꺼내기
		for(int i=0;i<4;i++){ // 상하좌우 이동 시도
			int nx = curX+dx[i]; // 새로운 x 좌표
			int ny = curY+dy[i]; // 새로운 y 좌표

			// 격자 범위 내에 있고, 집이 있고, 방문하지 않은 격자라면
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]&&!visited[nx][ny]){ 
				q.push({nx,ny}); // 큐에 새로운 좌표 넣기
				visited[nx][ny] = true; // 새로운 격자를 방문했다고 표시
				cnt++; // 단지 내 집의 수 증가
			}
		}
	}
	houses.push_back(cnt); // 단지 내 집의 수를 벡터에 저장
}


int main(){
	
	cin >> N; // 격자의 크기 입력받기
	
	for(int i=0;i<N;i++){ // 격자 정보 입력받기
		for(int j=0;j<N;j++){
			scanf("%1d",&map[i][j]); // 한 자리 수로 입력받음
		}
	}
	
	for(int i=0;i<N;i++){ // 격자를 전부 탐색
		for(int j=0;j<N;j++){
			
			if(map[i][j] && !visited[i][j]){ // 집이 있고, 방문하지 않은 격자라면
				BFS(i,j); // BFS 실행하여 단지 내 집의 수 구하기
			}
		}
	}	
	
	sort(houses.begin(),houses.end()); // 단지 내 집의 수를 오름차순 정렬
	
	cout << houses.size()<< endl; // 총 단지 수 출력
	for(int elem:houses){ // 단지 내 집의 수 출력
		cout << elem << endl;
	}
		
	
	
	return 0;
}
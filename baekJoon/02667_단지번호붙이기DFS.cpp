#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
이 코드는 주어진 격자에서 단지를 찾고 각 단지 내 집의 수를 구하는 문제를 해결하는 코드입니다. 

격자의 최대 크기와 상하좌우 이동을 위한 dx, dy 배열을 정의합니다.
격자 정보와 방문 정보를 저장할 2차원 배열, 
단지 내 집의 수를 저장할 벡터를 선언합니다.
DFS 함수는 특정 격자를 시작으로 재귀적으로 연결된 집들을 탐색하여 단지 내 집의 수를 구합니다.

main 함수에서는 격자 정보를 입력받고, 
모든 격자를 탐색하며 DFS 함수를 호출하여 단지 내 집의 수를 구합니다.

구한 단지 내 집의 수를 오름차순으로 정렬하고, 총 단지 수와 각 단지 내 집의 수를 출력합니다.
이와 같은 과정을 통해 주어진 격자에서 단지를 찾고 각 단지 내 집의 수를 구할 수 있습니다.

*/


const int MAX = 25; // 격자의 최대 크기 정의
// up down left right  
int dx[4] = {0,0,1,-1}; // x 좌표 변화를 나타내는 배열
int dy[4] = {1,-1,0,0}; // y 좌표 변화를 나타내는 배열

int map[MAX][MAX]; // 격자 정보를 저장할 2차원 배열
bool visited[MAX][MAX]; // 격자 방문 정보를 저장할 2차원 배열
vector <int> houses; // 단지 내 집의 수를 저장할 벡터
int N; // 격자의 크기

void DFS(int x,int y,int& cnt){ // DFS 함수
	
	if(visited[x][y]) return; // 이미 방문한 격자라면 리턴
	
	visited[x][y] = true; // 현재 격자를 방문했다고 표시
	cnt++; // 단지 내 집의 수 증가
	
	for(int i=0;i<4;i++){ // 상하좌우 이동 시도
		int nx = x+dx[i]; // 새로운 x 좌표
		int ny = y+dy[i]; // 새로운 y 좌표

		// 격자 범위 내에 있고, 집이 있고, 방문하지 않은 격자라면
		if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]&&!visited[nx][ny]){ 
			DFS(nx,ny,cnt); // 재귀적으로 DFS 실행
		}
	}
	
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
				int count = 0;
				DFS(i,j,count); // DFS 실행하여 단지 내 집의 수 구하기
				houses.push_back(count); // 단지 내 집의 수를 벡터에 저장
			}	
	
		}
	}
	
	sort(houses.begin(),houses.end()); // 단지 내 집의 수를 오름차순 정렬
	cout << houses.size()<<endl; // 총 단지 수 출력
	for(int elem:houses){ // 단지 내 집의 수 출력
		cout << elem << endl;
	}	

	return 0;
} 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 26; // ������ �ִ� ũ�� ����

int map[MAX][MAX]; // ���� ������ ������ 2���� �迭
bool visited[MAX][MAX]; // ���� �湮 ������ ������ 2���� �迭
int N; // ������ ũ��
int dx[4] = {0,0,1,-1}; // x ��ǥ ��ȭ�� ��Ÿ���� �迭
int dy[4] = {1,-1,0,0}; // y ��ǥ ��ȭ�� ��Ÿ���� �迭

queue<pair<int,int>>q; // BFS�� ���� ť
vector<int>houses; // ���� �� ���� ���� ������ ����

void BFS(int x,int y){ // BFS �Լ�
	visited[x][y] = true; // ���� ���ڸ� �湮�ߴٰ� ǥ��
	q.push({x,y}); // ť�� ���� ���� ��ǥ �ֱ�
	int cnt = 0; 
	cnt++; // ���� �� ���� �� ����

	while(!q.empty()){ // ť�� �� ������ �ݺ�
		int curX = q.front().first; // ���� x ��ǥ
		int curY = q.front().second; // ���� y ��ǥ
		q.pop(); // ť���� ���� ��ǥ ������
		for(int i=0;i<4;i++){ // �����¿� �̵� �õ�
			int nx = curX+dx[i]; // ���ο� x ��ǥ
			int ny = curY+dy[i]; // ���ο� y ��ǥ

			// ���� ���� ���� �ְ�, ���� �ְ�, �湮���� ���� ���ڶ��
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]&&!visited[nx][ny]){ 
				q.push({nx,ny}); // ť�� ���ο� ��ǥ �ֱ�
				visited[nx][ny] = true; // ���ο� ���ڸ� �湮�ߴٰ� ǥ��
				cnt++; // ���� �� ���� �� ����
			}
		}
	}
	houses.push_back(cnt); // ���� �� ���� ���� ���Ϳ� ����
}


int main(){
	
	cin >> N; // ������ ũ�� �Է¹ޱ�
	
	for(int i=0;i<N;i++){ // ���� ���� �Է¹ޱ�
		for(int j=0;j<N;j++){
			scanf("%1d",&map[i][j]); // �� �ڸ� ���� �Է¹���
		}
	}
	
	for(int i=0;i<N;i++){ // ���ڸ� ���� Ž��
		for(int j=0;j<N;j++){
			
			if(map[i][j] && !visited[i][j]){ // ���� �ְ�, �湮���� ���� ���ڶ��
				BFS(i,j); // BFS �����Ͽ� ���� �� ���� �� ���ϱ�
			}
		}
	}	
	
	sort(houses.begin(),houses.end()); // ���� �� ���� ���� �������� ����
	
	cout << houses.size()<< endl; // �� ���� �� ���
	for(int elem:houses){ // ���� �� ���� �� ���
		cout << elem << endl;
	}
		
	
	
	return 0;
}
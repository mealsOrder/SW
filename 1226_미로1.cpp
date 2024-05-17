#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;


/*

�� ������ �ٽ��� 
ť�� �ʱ�ȭ�ϴ� �� 
�̷� �������� ���� ����(2)�� ���� ����(3)�� ��ǥ�� �޾� 0���� �������ִ� ��

�̷� ������ �湮 ���� �迭, ����/���� ���� ��ǥ ���� ���̽����� �ʱ�ȭ�մϴ�.
�� �׽�Ʈ ���̽����� ť�� �ʱ�ȭ�Ͽ� ���� �׽�Ʈ ���̽��� ������ ���� �ʵ��� �մϴ�.
���� ����(2)�� ���� ����(3)�� ��ǥ�� ���� �����ϰ� �ش� ��ġ�� 0���� �����մϴ�.
BFS �˰����� �̿��Ͽ� ���� �������� ���� ���������� ��θ� Ž���մϴ�.
���� ������ �����ϸ� 1�� ��ȯ�ϰ�, �������� ���ϸ� 0�� ��ȯ�մϴ�.

*/


const int MAX = 17; // ������ �ִ� ũ�� ��� ����

int map[MAX][MAX]; // �̷� ������ ������ 2���� �迭

int dx[4] = {0,0,1,-1}; // �����¿� ���� ��Ÿ ��
int dy[4] = {1,-1,0,0};
int si,sj; // ���� ��ǥ
int ei,ej; // ���� ��ǥ
bool visited[MAX][MAX]; // �湮 ���� üũ �迭
queue<pair<int,int>> q; // BFS Ž���� ���� ť

// BFS �˰����� �̿��Ͽ� ���� �������� ���� ���������� ��� Ž��
int BFS(int x,int y){
    visited[x][y] = true; // ���� ���� �湮 ó��
    q.push({x,y}); // ���� ������ ť�� ����

    while(!q.empty()){ // ť�� �� ������ �ݺ�
        int curX = q.front().first; // ���� ����� x��ǥ
        int curY = q.front().second; // ���� ����� y��ǥ
        if(curX == ei && curY == ej) return 1; // ���� ������ �����ϸ� 1 ��ȯ
        q.pop(); // ���� ��� ť���� ����

        for(int i=0;i<4;i++){ // �����¿� ���� Ž��
            int nx = curX+dx[i]; // ���� x��ǥ
            int ny = curY+dy[i]; // ���� y��ǥ

            // ���� ��ǥ�� ���� ���� ���̰�, ���� �ƴϸ�, ���� �湮���� ���� ���
            if(nx>=0&&nx<16&&ny>=0&&ny<16&& map[nx][ny]==0 && !visited[nx][ny]){
                visited[nx][ny] = true; // ���� ��ǥ �湮 ó��
                q.push({nx,ny}); // ���� ��ǥ�� ť�� ����
            }
        }
    }

    return 0; // ���� ������ �������� ���� ��� 0 ��ȯ
}

int main(){
    for(int t=1;t<=10;t++){ // �� 10���� �׽�Ʈ ���̽�
        int num;
        cin >> num;
        memset(map,0,sizeof(map)); // �̷� ���� �ʱ�ȭ
        memset(visited,false,sizeof(visited)); // �湮 ���� �迭 �ʱ�ȭ
        while(!q.empty()) q.pop(); // ť �ʱ�ȭ

        // �̷� ���� �Է� �ޱ�
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                scanf("%1d",&map[i][j]);
                // ���� ����(2)�� ���� ����(3)�� ��ǥ ���� �� �ش� ��ġ�� 0���� ����
                if(map[i][j] == 2){
                    map[i][j] = 0;
                    si=i;
                    sj=j;
                }
                else if(map[i][j]==3){
                    map[i][j] = 0;
                    ei=i;
                    ej=j;
                }
            }
        }

        // BFS �˰����� �̿��� ��� �������� ���� ���������� ��� Ž��
        cout << "#" << t << " " << BFS(si,sj) << endl;
    }

    return 0;
}
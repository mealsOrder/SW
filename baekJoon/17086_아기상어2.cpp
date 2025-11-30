#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int dx[8] ={0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] ={1, -1, 0, 0, 1, 1, -1, -1};

int N, M;
int board[51][51];
int dist[51][51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    queue<pair<int, int>> q;

    // 입력 및 초기 설정
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                q.push({i, j});
                dist[i][j] = 0;
            } else{
                dist[i][j] = -1;  // 아직 방문 안한 칸 표시
            }
        }
    }

    // 다중 소스 BFS
    while (!q.empty()){
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;  // 이미 방문

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // 결과 계산
    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
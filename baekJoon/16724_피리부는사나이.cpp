#include <iostream>
using namespace std;
int board[1002][1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, ans;
void dfs(int x, int y){
    vis[x][y] = 1;
    int nx = x + dx[board[x][y]];
    int ny = y + dy[board[x][y]];
    if(vis[nx][ny] == 1) ans++; // 이미 1번 방문한 곳 = 1사이클을 돈 것이므로 ans += 1후, vis를 2로 바꾸어 더이상 인식 못하게 함
    if(vis[nx][ny] == 0) dfs(nx, ny);
    vis[x][y] = 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++){
            char a;
            cin >> a;
            if(a == 'U') board[i][j] = 2;
            else if(a == 'L') board[i][j] = 3;
            else if(a == 'R') board[i][j] = 1;
            else board[i][j] = 0;
        }

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(vis[i][j] == 0)
                dfs(i, j);

    cout << ans;
    return 0;
}
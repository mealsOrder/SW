#include <iostream>

using namespace std;

int n, answer = 0;
bool map[16][16];
int dr[3] = {0, 1, 1};
int dc[3] = {1, 0, 1};

void DFS(int r, int c, int prevDir) {
    if (r == n - 1 && c == n - 1) {
        answer++;
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        if ((prevDir == 0 && i == 1) || (prevDir == 1 && i == 0)) {
            continue;
        }
        
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        // 직접 조건 작성
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc]) {
            continue;
        }
        if (i == 2 && (map[r + 1][c] || map[r][c + 1])) {
            continue;
        }
        
        DFS(nr, nc, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> map[i][j];
        }
    }
    
    DFS(0, 1, 0);
    
    cout << answer;
    
    return 0;
}
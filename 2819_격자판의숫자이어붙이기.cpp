#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<set>

using namespace std;


/*
이 코드는 4x4 크기의 글자판에서 7자리 숫자를 만드는 문제를 해결합니다.

s set 자료구조를 이용하여 만들어진 7자리 숫자를 중복 없이 저장합니다.
DFS 함수를 이용하여 모든 위치에서 7자리 숫자를 만드는 과정을 수행합니다.
7자리 숫자를 만들었다면 s set에 추가합니다.
상하좌우 방향으로 탐색하며 현재 위치의 글자를 추가하여 
다음 위치로 DFS 탐색을 진행합니다.
글자판 범위를 벗어나는 경우 continue합니다.
모든 테스트 케이스에 대해 위 과정을 수행하고, 
최종적으로 만들어진 7자리 숫자의 개수를 출력합니다.

set 자료구조를 이용하여 중복된 숫자를 제거하였습니다.

*/


int dx[4] = {0,0,1,-1}; // 상하좌우 방향 델타 값
int dy[4] = {1,-1,0,0};
char map[4][4]; // 4x4 크기의 글자판 정보를 저장할 2차원 배열
set<string> s; // 만들어진 7자리 숫자를 저장할 set 자료구조

// DFS 알고리즘을 이용하여 글자판에서 7자리 숫자 만들기
void DFS(int x, int y, int cnt, string num) {
    // 7자리 숫자를 만들었다면 set에 추가하고 함수 종료
    if (cnt == 7) {
        s.insert(num);
        return;
    }

    // 상하좌우 방향으로 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 글자판 범위를 벗어나면 continue
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

        // 현재 위치의 글자를 추가하여 다음 위치로 DFS 탐색 진행
        DFS(nx, ny, cnt + 1, num + map[nx][ny]);
    }
}

int main() {
    int T; // 테스트 케이스의 개수
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // set 자료구조 초기화
        s.clear();

        // 글자판 정보 입력 받기
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }

        // 모든 위치에서 DFS 탐색 수행
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                DFS(i, j, 0, "");
            }
        }

        // 만들어진 7자리 숫자의 개수 출력
        cout << "#" << t << " " << s.size() << endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
const int MX = 51; // 지도의 최대 크기 정의
string map[MX]; // 지도를 저장할 2차원 배열 선언

int main() {
    ios_base::sync_with_stdio(0); // 입출력 속도 향상을 위한 설정
    cin.tie(0);
    cout.tie(0);

    int N,M; // 지도의 크기 입력받기
    cin >> N >> M;

    int cnt = 0; // 연결된 구역의 개수를 저장할 변수

    for (int i = 0; i < N; i++){ // 지도 입력받기
        cin >> map[i];
        for (int j = 0; j < M; j++){
            if (map[i][j] == '-'){ // 가로 선분인 경우
                if (j == 0 || map[i][j - 1] != '-') cnt++; // 왼쪽에 연결된 선분이 없으면 새로운 구역으로 간주
            } else if (map[i][j] == '|'){ // 세로 선분인 경우
                if (i == 0 || map[i - 1][j] != '|') cnt++; // 위쪽에 연결된 선분이 없으면 새로운 구역으로 간주
            }
        }
    }

    cout << cnt << '\n'; // 연결된 구역의 개수 출력
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 4;    // 4x4 크기의 보드
const int shk = 17; // 상어를 나타내는 번호

// 4x4 크기의 보드 및 물고기 좌표 정보
vector<vector<pair<int,int>>> board(4);
vector<pair<int,int>> coord;

// 8방향 이동 (상, 좌상, 좌, 좌하, 하, 우하, 우, 우상)
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

// 격자 밖으로 나가는지 확인하는 함수
bool oob(int x,int y){
    return x>=N || x<0 || y>=N || y<0;
}

// 재귀적으로 상어와 물고기의 이동을 처리하고 최대 점수를 구하는 함수
int solve(vector<vector<pair<int,int>>> b, vector<pair<int,int>> co){
    // 1번 물고기부터 16번 물고기까지 차례로 이동
    for(int no=1;no<=16;no++){
        // 현재 물고기의 좌표
        int cx = co[no].first;
        int cy = co[no].second;
        
        if(cx == -1 || cy == -1) continue; // 물고기가 없는 경우
        int dir = b[cx][cy].second; // 현재 물고기의 방향
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        // 이동할 수 없으면 방향을 변경
        while(oob(nx,ny) || b[nx][ny].first == shk){
            dir = (dir+1)%8;
            nx = cx + dx[dir];
            ny = cy + dy[dir];
        }
        b[cx][cy].second = dir; // 새로운 방향 업데이트

        // 물고기 위치를 교환
        co[no] = {nx,ny};
        co[b[nx][ny].first] = {cx,cy};
        b[cx][cy] = b[nx][ny];
        b[nx][ny] = {no,dir};
    }

    int ans = 0;
    
    // 상어의 현재 위치
    int cx = co[shk].first;
    int cy = co[shk].second;
    
    int dir = b[cx][cy].second; // 상어의 이동 방향

    // 상어는 1~3칸까지 이동 가능
    for(int p=1;p<=3;p++){
        int nx = cx + p*dx[dir];
        int ny = cy + p*dy[dir];
        if(oob(nx,ny) || !b[nx][ny].first) continue;

        // 이동 후 상태를 복사하여 다음 경우 탐색
        vector<vector<pair<int,int>>> tmpb = b;
        vector<pair<int,int>> tmpco = co;
        int no = tmpb[nx][ny].first;
        tmpb[nx][ny].first = shk;
        tmpco[shk] = {nx,ny};
        tmpco[no] = {-1,-1};
        tmpb[cx][cy] = {0,0};
        ans = max(ans, no + solve(tmpb,tmpco)); // 점수 갱신
    }

    return ans;
}

// 초기 상태 설정 함수
void setup(){
    coord.resize(19); // 물고기 번호는 1~16번, 상어는 17번
    for(int i=0;i<N;i++){
        board[i].resize(4);
        for(int j = 0;j<N;j++){
            int no, dir;
            cin >> no >> dir;   // 물고기 번호와 방향 입력
            board[i][j] = {no,dir-1}; // 방향은 0부터 시작
            coord[no] = {i,j}; // 물고기의 좌표 저장
        }
    }
}

// 메인 함수
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    setup(); // 초기 설정
    int no  = board[0][0].first; // (0,0)의 물고기 번호
    board[0][0].first = shk;     // 상어가 (0,0) 위치로 이동
    coord[no] = {-1,-1};         // 상어가 물고기를 잡아먹음
    coord[shk] = {0,0};          // 상어의 좌표 저장
    cout << no + solve(board,coord) << '\n'; // 최대 점수 출력
	return 0;
}

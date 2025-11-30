#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;

bool isValid(int x, int y, int val){
    // 가로, 세로 검사
    for(int i = 0; i < 9; ++i){
        if(board[x][i] == val || board[i][y] == val)
            return false;
    }
    // 3x3 박스 검사
    int boxX =(x / 3) * 3;
    int boxY =(y / 3) * 3;
    for(int i = boxX; i < boxX + 3; ++i){
        for(int j = boxY; j < boxY + 3; ++j){
            if(board[i][j] == val)
                return false;
        }
    }
    return true;
}

bool solve(int idx){
    if(idx == blanks.size()){
        // 모든 빈칸을 채운 경우
        return true;
    }

    int x = blanks[idx].first;
    int y = blanks[idx].second;

    for(int num = 1; num <= 9; ++num){
        if(isValid(x, y, num)){
            board[x][y] = num;
            if(solve(idx + 1))
                return true;
            board[x][y] = 0; // 백트래킹
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0)
                blanks.push_back({i, j});
        }
    }

    solve(0);

    // 결과 출력
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

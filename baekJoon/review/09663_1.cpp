#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 16;
int N,cnt;
int board[MX];
// pram x  행 번호
// x행과 연관된 열과 대각선에 놓을 수 있는지 체크한다.
bool isValid(int x){
    for(int i=0;i<x;i++){
        if(board[i] == board[x] || abs(board[i] - board[x]) == x-i)return false;
    }
    return true;
}
//
void back(int x){
    if(x==N){
        cnt++;
        return;
    }
    for(int j=0;j<N;j++){
        board[x] = j;
        if(isValid(x)){
            back(x+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(board,board+N,0);
    back(0);
    cout << cnt;
    return 0;
}
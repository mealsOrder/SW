#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 16;
int N,cnt;
int board[MX];

bool isValid(int x){
    for(int i=0;i<x;i++){
        if(board[i] == board[x] || abs(board[i] - board[x]) == x-i ){
            return false;
        }
    }
    return true;
}

void func(int x){
    if(x == N){
        cnt++;
        return;
    }
    for(int j=0;j<N;j++){
        board[x] = j;
        if(isValid(x)){
            func(x+1);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N;

    func(0);

    cout << cnt << '\n';

	return 0;
}
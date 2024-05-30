#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;

const int MAX = 16;

int board[MAX]; // 체스판 상황을 저장하는 배열
int N,cnt; // N은 체스판 크기, cnt는 경우의 수 저장용 변수

// 현재 위치(행번호) x에 퀸을 두는 것이 가능한지 체크하는 함수
bool isValid(int x){
	for(int i=0;i<x;i++){
		// 같은 열에 있거나 대각선 상에 있으면 불가능
		if(board[i]==board[x] || abs(board[i]-board[x]) == x-i ){
			return false;
		}
	}
	return true;
}

// 백트래킹 함수
void back(int x){
	if(x == N){ // 퀸을 N개 모두 배치했다면
		cnt++; // 경우의 수 증가
		return;
	}
	
	for(int j=0;j<N;j++){ // 체스판의 모든 열에 대해
		board[x] = j; // x행 j열에 퀸을 놓아 본다
		if( isValid(x) ){ // 이 위치에 퀸을 둘 수 있다면
			back(x+1); // 다음 행으로 진행
		}
		
	}
	
}

int main(){
	
	cin >> N; // 체스판 크기 입력 받기
	cnt = 0; // 경우의 수 초기화
	memset(board,0,sizeof(board)); // 체스판 초기화
	back(0); // 0번째 행부터 시작
	cout << cnt << '\n'; // 총 경우의 수 출력
    

	

	return 0;
}
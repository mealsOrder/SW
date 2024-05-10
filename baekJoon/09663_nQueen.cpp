#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;

const int MAX = 16;

int board[MAX];
int N,cnt;

bool isValid(int x){
	for(int i=0;i<x;i++){
		if(board[i]==board[x] || abs(board[i]-board[x]) == x-i ){
			return false;
		}
	}
	return true;
}

void back(int x){
	if(x == N){
		cnt++;
		return;
	}
	
	for(int j=0;j<N;j++){
		board[x] = j;
		if( isValid(x) ){
			back(x+1);
		}
		
	}
	
}

int main(){
	
	cin >> N;
	cnt = 0;
	memset(board,0,sizeof(board));
	back(0);
	cout << cnt << endl;
    

	

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 40;
int N;
int cnt;
bool visited1[MX]; //   열에 놓여 있는지
bool visited2[MX]; //  /위 대각에 놓여 있는지
bool visited3[MX]; //  \아래 대각 놓여 있는지

// cur번째 행에 말을 배치 ex. 8*8 이면 0~7행
void func(int cur){
    if(cur==N){ // N개를 놓는데 성공
        cnt++;
        return;
    }
    // (cur,i)에 놓을 예정
    for(int i=0;i<N;i++){
        // 열방향 대각선 방향에 퀸이 이미 있다면 pass!
        if(visited1[i] || visited2[cur+i] || visited3[cur-i+N-1])
            continue;
        visited1[i]=1;
        visited2[i+cur]=1;
        visited3[cur-i+N-1]=1;
        func(cur+1);
        visited1[i]=0;
        visited2[i+cur]=0;
        visited3[cur-i+N-1]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}
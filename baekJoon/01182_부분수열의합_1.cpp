#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 22;
int arr[MAX];
int N,S;
int cnt=0;
// 0                        0
// 1              0                 -7
// 2        0         -3        -7       -10 
// 3    0    -2    -3    -5  -7  -9   -10   -12
// 4  ...
// 모든 경우의 수 :아무것도 없는 수열~ 모든숫자가 들어간 수열 
// 16 >>
// if sum == S 해버리면 S가 0 일때 공집합인 경우도 들어가서 -1해줘야 하지만
// if sum+arr[idx] == S 하면 왜 잘 나오지??? 흠...
void f(int idx,int sum){
    // 모든 수를 다 더하면 종료
    if(idx == N) return;
    // 지금까지의 합에서 현재 인덱스의 수를 더한값이 목표값이면 1증가
    if(sum+arr[idx] == S) cnt++;
    
    // 현재 인덱스의 값을 포함하지 않음
    f(idx+1,sum); 
    // 현재 인덱스의 값을 포함
    f(idx+1,sum + arr[idx]);
}

int main() {
    
    
    cin >>N>>S;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    cnt= 0;
    f(0,0);
    cout << cnt;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

/**
 * 오답 코드
 * 입력 중에  long long 범위를 벗어나는 입력이 있는데
 * 어떻게 처리 해야 할지 모르겠음...
 * 제출은 파이썬으로 제출함ㅠ
 */

const int MX = 1001;
const long long SM = LONG_LONG_MIN;
long long arr[MX][MX];
long long A[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int M,N;
        cin >>M>>N;
        for(int j=0;j<N;j++){
            for(int i=0;i<M;i++){
                cin >> arr[j][i];
            }
        }
        long long ans = SM; // long long 값의 최소값으로 초기화
        int idx = 0;
        for(int i=0;i<M;i++){
            A[i] = 1; // 초기화 필!
            for(int j=0;j<N;j++){
                A[i] *= arr[j][i];
            }
            if(A[i] >= ans){
                ans = A[i];
                idx = i;
            }
        }
        cout << idx+1 << '\n';
    }
    
    return 0;
}
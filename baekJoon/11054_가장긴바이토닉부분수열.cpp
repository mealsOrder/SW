#include<iostream>  
#include<vector>    
#include<algorithm> 
#include<queue>     
using namespace std;

const int MX = 1001; // 배열의 최대 크기 설정
int dp[MX]; // 왼쪽에서 오른쪽으로 증가하는 부분 수열의 길이를 저장하는 배열
int dp_r[MX]; // 오른쪽에서 왼쪽으로 증가하는 부분 수열의 길이를 저장하는 배열
int arr[MX]; // 입력 배열을 저장하는 배열

int main(){
    ios_base::sync_with_stdio(false); // 입출력 속도 최적화
	cin.tie(0); // 입력과 출력의 동기화 해제
	cout.tie(0); // 출력의 버퍼링 최적화
    
    int N; // 수열의 길이
    cin >> N; // 수열의 길이를 입력받음

    // 수열의 원소들을 입력받고 dp와 dp_r 배열을 초기화
    for(int i=0; i<N; i++){
        cin >> arr[i]; // 수열의 i번째 원소 입력
        dp[i] = dp_r[i] = 1; // 각 위치에서의 최장 증가 부분 수열 초기값은 1
    }

    // 왼쪽에서 오른쪽으로 진행하며 증가하는 부분 수열 길이 계산
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            // arr[i] > arr[j] 조건: 앞에 있는 원소보다 현재 원소가 클 때
            // 증가하는 부분 수열이기 때문에 dp[i]를 갱신
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }

    // 오른쪽에서 왼쪽으로 진행하며 증가하는 부분 수열 길이 계산
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>i; j--){
            // arr[i] > arr[j] 조건: 뒤에 있는 원소보다 현재 원소가 클 때
            // 증가하는 부분 수열이기 때문에 dp_r[i]를 갱신
            if(arr[i] > arr[j]){
                dp_r[i] = max(dp_r[i], dp_r[j] + 1);
            }
        }
    }

    int ans = 0; // 정답을 저장할 변수

    // dp와 dp_r 배열을 합쳐 가장 긴 바이토닉 수열의 길이 계산
    for(int i=0; i<N; i++){
        // dp[i]와 dp_r[i]를 합친 길이에서 중복된 i번째 원소를 1회 제외
        ans = max(ans, dp[i] + dp_r[i]);
    }

    cout << ans - 1 << '\n'; // 최종 결과 출력 (중복된 원소 하나 제외)
    return 0;
}

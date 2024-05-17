#include<iostream>  
#include<vector>    
#include<algorithm> 
#include<queue>     
using namespace std;

const int MAX = 1001;  // 입력 배열의 최대 크기 상수 정의
int A[MAX];           // 입력 받은 숫자들을 저장할 배열
int DP[MAX];         // 동적 프로그래밍을 위한 배열

int main(){
    int N;  // 입력 받을 숫자의 개수
    
    // 숫자의 개수 N 입력 받기
    cin >> N;
    
    // 각 숫자를 입력 받아 A 배열에 저장
    for(int t=1;t<=N;t++){
        cin >> A[t];
    }
    

    for(int i=1;i<=N;i++){
        // 현재 숫자 A[i]를 포함하는 가장 긴 증가 부분 수열의 길이 초기화
        DP[i] = A[i];
        
        // 이전 숫자들 A[j]와 비교하여 가장 긴 증가 부분 수열 길이 갱신
        // DP[a]=b : a번 인덱스 까지의 가장 큰 부분 수열의 합b
        for(int j=1;j<i;j++){
            if(A[i] > A[j] ){
                DP[i] = max(DP[i],A[i]+DP[j]);
            }
        }
    }
    
    // 가장 긴 증가 부분 수열의 길이 찾기
    int ans=0;
    for(int i=1;i<=N;i++){
        ans = max(ans,DP[i]);
    }
    
    // 가장 긴 증가 부분 수열의 길이 출력
    cout << ans << endl;
    
    return 0;
}
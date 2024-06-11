#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MX = 101;

int main(){
    ios_base::sync_with_stdio(0); // 입출력 속도 향상을 위한 설정
    cin.tie(0); cout.tie(0); // 입출력 속도 향상을 위한 설정
    int T; // 테스트 케이스의 수
    cin >> T;
    while(T--){ // 각 테스트 케이스에 대해
        int N,M; // 문서의 개수 N과 찾고자 하는 문서의 위치 M
        cin >> N >>M;
        vector<int>v(N); // 문서의 우선순위를 저장하는 벡터
        queue<pair<int,int>>q; // 문서의 우선순위와 위치를 저장하는 큐
        for(int i=0;i<N;i++){
            cin >> v[i]; // 문서의 우선순위 입력
            q.push({v[i], i}); // 문서의 우선순위와 위치를 큐에 삽입
        }
        sort(v.begin(),v.end(),greater<>()); // 문서의 우선순위를 내림차순으로 정렬
        int cnt =0, idx = 0; // 출력된 문서의 수(cnt)와 현재 확인하고 있는 우선순위의 인덱스(idx)
        while(!q.empty()){
            int prime = q.front().first; // 큐의 맨 앞 문서의 우선순위
            int loc = q.front().second; // 큐의 맨 앞 문서의 위치
            q.pop();

            if(prime == v[idx] ){ // 만약 현재 문서의 우선순위가 가장 높다면
                cnt++; // 출력된 문서의 수 증가
                idx++; // 다음으로 높은 우선순위로 이동
                if(loc == M){ // 만약 출력된 문서가 찾고자 하는 문서라면
                    cout << cnt << '\n'; // 출력된 문서의 수 출력
                    break;
                }
            }else{ // 만약 현재 문서의 우선순위가 가장 높지 않다면
                q.push({prime,loc}); // 문서를 큐의 맨 뒤로 이동
            }
        }

    }

	return 0;
}

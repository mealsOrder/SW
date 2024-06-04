#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

// 사용자 정의 비교 함수 객체
struct minAbs{
    // operator() 함수 오버로딩
    bool operator()(int a, int b){
        // 두 수의 절대값이 같으면 실제 값을 비교
        if(abs(a) == abs(b)){
            return a>b;
        }
        // 그렇지 않으면 절대값을 비교
        return abs(a)>abs(b);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;  // 입력 받을 숫자의 개수
    cin >>N;

    vector<int>v(N);  // 숫자를 저장할 벡터
    // minAbs 비교 함수 객체를 사용하여 우선순위 큐 생성
    priority_queue<int,vector<int>,minAbs>pq;

    for(int i=0;i<N;i++){
        cin >> v[i];  // 숫자 입력 받기
        
        // 입력 받은 숫자가 0이면
        if(v[i] == 0){
            // 우선순위 큐가 비어 있지 않으면
            if(!pq.empty()){
                // 가장 작은 숫자를 출력하고 제거
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                // 우선순위 큐가 비어 있으면 0 출력
                cout << "0\n";
            }
        }
        else{
            // 입력 받은 숫자가 0이 아니면 우선순위 큐에 추가
            pq.push(v[i]);
        }
        
    }

    return  0;
}

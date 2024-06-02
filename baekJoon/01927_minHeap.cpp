#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    // 크기 N 인 벡터 배열
    vector<int>v(N);

    // 오름차순 정렬 우선순위 큐 
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<N;i++){
        cin >> v[i];
        // 입력이 0이면
        if(v[i] == 0){
            // 큐가 비어 있지 않으면
            if(!pq.empty()){
                // 맨위 원소 출력하고 값 제거
                cout << pq.top() << '\n';
                pq.pop();
            }
            // 큐가 비어 있으면 0 출력
            else{
                cout << "0" << '\n';
            }
        }
        // 입력이 0이 아니면 큐에 값 추가
        else{
            pq.push(v[i]);
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<pair<int,int>,int>>v;// {{끝,시작}, 번호}
vector<int>ans; // 결과 출력용 벡토
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int num, s, e;
        cin >> num >> s >> e;
        // {{끝,시작}, 번호} 벡터에 푸시
        v.push_back({{e,s},num});
    }
    // 끝나는 시간을 기준으로 정렬
    sort(v.begin(),v.end());
    int cnt = 0;   // 회의실 개수
    int endTime=0; // 직전에 끝나는 시간 저장

    // 정렬된 벡터 돌면서
    for(int i=0;i<N;i++){
        // 시작 시간이 직전끝나는 시간보다 크거나 같다면
        if(v[i].first.second >= endTime){
            cnt++; // 회의실 개수 추가
            endTime = v[i].first.first; // 직전 끝나는 시간 업데이트
            ans.push_back(v[i].second); // 해당 회의실 번호 추가
        }
    }
    cout << cnt << '\n';
    for(int k:ans){
        cout << k << " "; 
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 공유기를 mid 거리만큼 설치할 수 있는지 확인
bool check(vector<int>& v, int mid, int c){
    int cnt = 1;        // 첫번째 집에는 항상 공유기 설치
    int pre = v[0];     // 마지막으로 공유기 설치한 집 저장
    for(int i=1;i<v.size();i++){
        // 현재 집과 마지막으로 공유기를 설치한 집 사이의 거리가
        // mid 이상이면 공유기 설치후 그 위치를 갱신.
        if(v[i] - pre >= mid){
            cnt++;
            pre = v[i];
        }
    }
    return cnt>=c; // cnt>=c 이면 1, 아니면 0 반환
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,C;
    cin >> N>>C;
    vector<int>v(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end()); // 정렬해야 이분탐색 가능

    int lef = 1;            // 공유기 사이 최소거리 1
    int rig = v[N-1] - v[0];// 공유기 사이 최대거리
    int ans = 0;
    while(lef<=rig){
        int mid = (lef+rig)/2;
        // mid거리만큼 공유기를 설치할 수 있으면 거리를 늘림
        if(check(v,mid,C)){
            // 최대값 갱신
            if(ans < mid){
                ans = mid;
            }
            lef = mid+1;
        }
        // mid거리만큼 공유기를 설치할 수 없으면 거기 줄임
        else{
            rig = mid -1;
        }
    }

    cout << ans <<'\n';

    return 0;
}
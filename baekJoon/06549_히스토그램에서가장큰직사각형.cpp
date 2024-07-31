#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int N;
        cin >> N;
        if(N==0)break;
        stack<pair<ll,ll>>S; // [스택] {높이,그 높이의 위치}
        ll ans = 0;
        for(int i=0;i<N;i++){
            int h;
            cin >> h;
            int idx = i;
            // 스택이 비어있지 않고, 스택의 최상단 높이가 현재 높이보다 높거나 같으면
            while(!S.empty() && S.top().first >=h){
                // 스택의 최상단에서 면적 계산 (1LL은 형변환 쉽도록 그냥 곱해줌)
                ans = max(ans,1LL * (i-S.top().second)*S.top().first);
                idx = S.top().second;
                S.pop();
            }
            // 현재 높이와 인덱스를 스택에 추가
            S.push({h,idx});
        }
        // 스택에 남아있는 모든 막대에 대해 면적 계산
        while(!S.empty()){
            ans = max(ans, 1LL*(N-S.top().second)*S.top().first);
            S.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}
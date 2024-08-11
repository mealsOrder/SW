#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
typedef long long ll;
const int MX = 80001;
stack<int>s; 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll cnt=0;   
    int N;
    cin >>N;

    while(N--){
        int h;
        // 키 입력 받음 
        cin >> h;

        // 스택이 비어있으면 스택에 키 추가
        if(s.empty()) s.push(h);

        // 스택이 비어있지 않고,
        // 현재 최상단이 입력된 높이보다 낮거나 같으면 스택에서 제거
        // 이유 : 소들이 자기보다 키가 작은 애들만 볼수 있으니
        while(!s.empty() && s.top() <= h)s.pop();
        
        // 스택에 남아 있는 소 마리수 추가
        cnt += s.size();

        // 현재 키를 스택에 추가
        s.push(h);
    }

    // 답 출력
    cout << cnt << '\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N>>M;
    
    vector<long long>sum(N+1,0);// 누적합을 저장할 벡터
    vector<long long>cnt(M,0);// 나머지에 따른 개수를 저장할 벡터
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        sum[i] = (sum[i-1]+num)%M; // 누적합을 M으로 나눈 나머지를 저장
        cnt[sum[i]]++; // 해당 나머지의 개수를 증가
    }
    long long res = cnt[0]; // 합이 M으로 나누어 떨어지는 경우의 수를 저장할 변수
    for(int i=0;i<M;i++){
        if(cnt[i] >=2){ // 같은 나머지를 가지는 개수가 2개 이상인 경우
            res += cnt[i]*(cnt[i]-1)/2; // 조합의 개수를 더한다...
        }
    }
    cout << res << '\n';
    return 0;
}
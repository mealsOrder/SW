#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * 먼저 각 수에 대해 누적합을 구하고, 이를 M으로 나눈 나머지를 구합니다. 
 * 이 나머지는 0부터 M-1까지의 값 중 하나이므로, 
 * 각 나머지에 대해 그 나머지를 가지는 누적합의 개수를 세어 저장합니다. 
 * 이후 각 나머지에 대해 그 나머지를 가지는 누적합 중 
 * 2개를 선택하는 경우의 수를 구하고, 이를 모두 더하면 합이 
 * M으로 나누어 떨어지는 부분 수열의 개수를 구할 수 있습니다. 
 * 이는 두 누적합의 차가 M의 배수인 경우, 
 * 즉 두 누적합이 M으로 나눈 나머지가 같은 경우에 해당하는 부분 수열이 
 * 합이 M의 배수가 되기 때문입니다. 
 * 참고 링크
 * https://velog.io/@isohyeon/Java-%EB%B0%B1%EC%A4%80-10986-%EB%82%98%EB%A8%B8%EC%A7%80-%ED%95%A9
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N>>M;
    
    vector<long long>sum(N+1,0);    // 누적합을 저장할 벡터
    vector<long long>cnt(M,0);      // 나머지에 따른 개수를 저장할 벡터
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        sum[i] = (sum[i-1]+num)%M;  // 누적합을 M으로 나눈 나머지를 저장
        cnt[sum[i]]++;              // 해당 나머지의 개수를 증가
    }
    long long res = cnt[0];          // 합이 M으로 나누어 떨어지는 경우의 수를 저장할 변수
    for(int i=0;i<M;i++){
        if(cnt[i] >=2){                 // 같은 나머지를 가지는 개수가 2개 이상인 경우
            res += cnt[i]*(cnt[i]-1)/2; // nC2 = N*(N-1) / 2
        }
    }
    cout << res << '\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/**
 * @brief 원형 큐 문제
 * 
 */
const int MX = 20001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //수열갯수, 번호갯수
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N,M;
        queue<int>q;
        cin >> N >> M;
        int A[MX] = {0,};
        int flag[MX] = {0,};
        for(int i=1;i<=M;i++)q.push({i});
        for(int i=1;i<=M;i++) flag[i] = i;

        for(int i=1;i<=N;i++) cin >> A[i];
        int dist=1;
        int ans = 987987987;
        int cnt=1;
        for(int k=0;k<=M;k++){
            dist = 1;
            for(int i=1;i<=N;i++){
                if(flag[k] != i)q.push(i);
                else if(flag[k] == i) continue;
                while(cnt < N){
                    int cur = q.front();
                    
                    if( cur == A[i]){
                        dist++;
                        cnt++;
                        q.pop();
                        break;
                    }
                    else{
                        q.pop();
                        q.push(cur);
                        dist++;
                    }
                }
            }
            //cout << '\n';
            //cout << dist << '\n';
            ans = min(ans,dist);

        }
        cout << '#'<< t << ' ' << ans << '\n';
    }
    return 0;
}
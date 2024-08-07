#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N>>M;
    deque<int>dq;
    for(int i=1;i<=N;i++)dq.push_back(i);
    int ans = 0;
    for(int i=0;i<M;i++){
        int a;
        cin >> a;

        int idx = 0;
        for(int j=0;j<N;j++){
            if(dq[j] == a){
                idx = j;
                break;
            }
        }

        if(idx > dq.size()/2){
            while( dq.front() != a){
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        else{ // idx <= dq.size()/2
            while( dq.front() != a){
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            
        }

        dq.pop_front();
    }
    cout << ans << '\n';
    return 0;
}
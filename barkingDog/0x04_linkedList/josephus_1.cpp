#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

queue<int>q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin >>N>>K;
    for(int i=1;i<=N;i++)q.push(i);
    int cnt = 1;
    cout << "<";
    while(!q.empty()){
        int ans = q.front();
        if(cnt%K == 0){
            q.pop();
            if(q.empty()){
                cout << ans << ">";
            }
            else{
                cout << ans << ", ";
            }
        }
        else{
            q.pop();
            q.push(ans);
        }
        cnt++;
    }
	return 0;
}
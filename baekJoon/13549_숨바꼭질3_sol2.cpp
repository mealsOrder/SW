#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<deque>
using namespace std;
// 오답 코드 왜 안되는지 찾아야함 ...ㄴ
const int MX = 100001;
int N,K;
bool vis[MX];
int BFS(){
    queue<pair<int,int>>q; // {위치,시간}
    q.push({N,0});
    vis[N] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if(cur == K) return time;

        if(cur -1 >= 0 && !vis[cur-1]){
            vis[cur-1]=true;
            q.push({cur-1,time+1});
        }
        if(cur+1 <= 100000 && !vis[cur+1]){
            vis[cur+1]=true;
            q.push({cur+1,time+1});
        }
        if(cur*2 <=100000 && !vis[cur*2]){
            vis[cur*2] = true;
            q.push({cur*2,time});
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N>>K;
    
    int ans = BFS();

    cout << ans << '\n';
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<deque>
using namespace std;
const int MX = 100001;
const int INF = INT_MAX;
int N,K;
bool vis[MX];
int BFS(){
    queue<pair<int,int>>q; // {위치,시간}
    q.push({N,0});
    vis[N] = true;

    while(!q.empty()){
        int curPos = q.front().first;
        int curTime = q.front().second;
        q.pop();

        if(curPos == K) return curTime;

        if(curPos -1 >= 0 && !vis[curPos-1]){
            vis[curPos-1]=true;
            q.push({curPos-1,curTime+1});
        }
        if(curPos+1 <= 100000 && !vis[curPos+1]){
            vis[curPos+1]=true;
            q.push({curPos+1,curTime+1});
        }
        if(curPos*2 <=100000 && !vis[curPos*2]){
            vis[curPos*2] = true;
            q.push({curPos*2,curTime});
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
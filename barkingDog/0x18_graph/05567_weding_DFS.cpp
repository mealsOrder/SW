#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;
const int MX = 502;
vector<int>v[MX];
int vis[MX];
int cnt;
void DFS(){
    stack<int>s;
    vis[1] = true;
    s.push(1);

    while(!s.empty()){
        int curX = s.top();s.pop();

        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];
            
            if(vis[nx]) continue;

            vis[nx]=true;
            cnt++;
            if(curX == 1) s.push(nx); // 상근이의 이웃만 스택에 추가
        }
    }
}

int main(){
    int N,M;
    cin >>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS();
    cout << cnt;
    return 0;
}

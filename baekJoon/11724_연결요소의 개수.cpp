#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 1001;

queue<int>q;
vector<int>v[MAX];
vector<int>ans;
int N,M;
bool visited[MAX];
int cnt;

void BFS(int x){
    cnt = 1;
    visited[x]= true;
    q.push(x);

    while(!q.empty()){
        int curX = q.front();
        q.pop();
        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];

            if(!visited[nx]){
                q.push(nx);
                visited[nx]=true;
                cnt++;       
            }
        }

    }

    ans.push_back(cnt);
}

int main() {
    
    cin >> N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            BFS(i);
        }
    }
    
    cout << ans.size() << '\n';

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 300001;
const int INF = 987987987;

int N,M,K,X;
vector<int>v[MX];
vector<int>ans;
int dist[MX];

void func(){
    dist[X] = 0;
    queue<int>q; //{거리,노드}
    q.push(X);

    while(!q.empty()){
        int curNode = q.front();
        q.pop();

        for(int i=0;i<v[curNode].size();i++){
            int nxNode = v[curNode][i];

            if(dist[nxNode] >=0 )continue;

            dist[nxNode] = dist[curNode]+1;
            q.push(nxNode);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M>>K>>X;

    while(M--){
        int a,b;
        cin >> a>>b;
        v[a].push_back(b);

    }
    fill(dist,dist+N+1,-1);
    func();
    for(int i=1;i<=N;i++){
        if(dist[i] == K){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0)cout << "-1\n";
    else{
        for(int elem: ans) cout << elem << '\n';
    }
    return 0;
}
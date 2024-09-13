#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
const int MX = 11;
const int INF = 987987987;
int N,fi,la;
int W[MX][MX];
int path[MX][MX];
bool vis[MX];
int dist[MX];
vector<int>a;
vector<pair<int,int>>v[MX];
void func(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                W[i][j] = min(W[i][j],W[i][k]+W[k][j]);
            }
        }
    }
}

void BFS(int st){
    fi = st;
    fill(dist,dist+MX,INF);
    priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>  >q;
    dist[st] = 0;
    q.push({dist[st],st});
    while(!q.empty()){
        int curCost = q.top().first;
        int curNode = q.top().second;
        q.pop();
        if(dist[curNode] != curCost)continue;
        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode]>dist[curNode]+nxCost){
                dist[nxNode]>dist[curNode]+nxCost;
                q.push({dist[nxNode],nxNode});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> W[i][j];
            v[i].push_back({W[i][j],j});
        }
    }

    int inx = 0;
    int res;
    for(int i=0;i<N;i++){
        res=0;
        BFS(i);
        for(int j=0;j<N;j++){
            if(dist[j] != INF){
                if(res < dist[j]){
                    res = dist[j];
                    inx = i;
                }
                
            }
        }
        res += W[la][i];
        a.push_back(res);
    }
    cout << *max_element(a.begin(),a.end());
    return 0;
}
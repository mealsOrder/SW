#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

const int MX = 51;
vector<int>graph[MX];
int DFS(int x){
    int ans = 0;
    vector<int>v;
    for(int i=0;i<graph[x].size();i++){
        int nx = graph[x][i];
        v.push_back(DFS(nx));
    }
    
    sort(v.begin(),v.end(),greater<int>());

    for(int i=0;i<v.size();i++){
        ans = max(ans,v[i]+i+1);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int root;
    cin >> root;

    for(int i=1;i<N;i++){
        int par;
        cin >> par;
        graph[par].push_back(i);
    }
    cout << DFS(0) << '\n';
    return 0;
}
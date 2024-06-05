#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
const int MX = 101;
bool arr[MX][MX];
bool vis[MX];
int N;
bool DFS(int x,int y){
    stack<int>s;
    fill(vis,vis+N+2,0);
    s.push(x);

    while(!s.empty()){
        int cur = s.top();
        s.pop();

        if(vis[cur])continue;
        if(cur != x) vis[cur] = true;

        for(int nx=0;nx<N;nx++){
            if(vis[nx])continue;
            if(arr[cur][nx]){
                if(nx == y)return true;
                s.push(nx);
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << DFS(i,j) << " ";
        }
        cout << '\n';
    }

    return 0;
}

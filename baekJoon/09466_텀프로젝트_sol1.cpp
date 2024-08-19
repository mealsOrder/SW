#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 100001;
int arr[MX];
bool vis[MX];
bool cycle[MX];
int N,cnt;
void DFS(int x){
    vis[x] = true;

    int nx = arr[x];
    if(!vis[nx])DFS(nx);
    else if(!cycle[nx]){
        for(int i=nx;i!=x;i=arr[i])cnt++;
        cnt++; // 자기 자신
    }
    cycle[x]=true;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N;
        fill(vis,vis+N+1,0);
        fill(cycle,cycle+N+1,0);
        for(int i=1;i<=N;i++){
            cin >> arr[i];
        }
        cnt=0;
        for(int i=1;i<=N;i++){
            if(!vis[i])DFS(i);
        }
        cout << N - cnt << '\n';
    }

    return 0;
}
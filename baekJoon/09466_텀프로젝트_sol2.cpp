#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 100005;
const int NOT = 0;
const int CYC = -1;
int arr[MX];
int N;
int vis[MX];
void DFS(int x){
    int cur = x;
    while(true){
        vis[cur] = x;
        cur=arr[cur];
        if(vis[cur] == x){
            while(vis[cur] != CYC){
                vis[cur] = CYC;
                cur = arr[cur];
            }
            return;
        }
        else if(vis[cur] != 0)return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N;
        fill(vis,vis+N+1,0);
        for(int i=1;i<=N;i++){
            cin >> arr[i];
        }
        for(int i=1;i<=N;i++){
            if(vis[i] == NOT)DFS(i);
        }
        int cnt=0;
        for(int i=1;i<=N;i++){
            if(vis[i] != CYC)cnt++;
        }
        cout << cnt << '\n';
    }


    return 0;
}
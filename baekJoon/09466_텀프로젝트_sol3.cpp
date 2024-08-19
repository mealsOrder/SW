#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 100005;
int T, N; 
int arr[MX]; 
int vis[MX];
/**
 * vis[x] 의 값이 의미하는 것
 * 1 방문, 순환 탐색중
 * 2 순환에 포함된 노드,
 * 3 순환 탐색이 완료된 노드
 */
void func(int x){
    vis[x] = 1;
    if(vis[arr[x]] >= 2){
        vis[x] = 3;
        return;
    }
    if(vis[arr[x]] == 1){
        while(vis[arr[x]] == 1){
            vis[arr[x]] = 2;
            x = arr[x];
        }
        return;
    }
    if(vis[arr[x]] == 0){
        func(arr[x]);
        if(vis[x] == 1){
            vis[x] = 3;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        int ans = 0;
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            vis[i] = 0;
        }
        for(int i = 1; i <= N; i++){
            if(vis[i] == 0){
                func(i);
            }
        }
        for(int i = 1; i <= N; i++){
            if(vis[i] == 3) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
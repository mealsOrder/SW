#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 201;
const int INF = 987987987;
int N,M;
int path[MX][MX];
int ans[MX][MX];
void func(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(path[i][j] > path[i][k]+path[k][j]){
                    path[i][j] = path[i][k]+path[k][j];
                    ans[i][j] = ans[i][k]; // i -> k -> j
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j) path[i][j] = 0;
            else path[i][j] = INF;        
        }
    }
    while(M--){
        int a, b, c;
        cin >> a>>b>>c;
        path[a][b] = c;
        path[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }
    func();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(ans[i][j] == 0){
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << " "; // 가장 가까운 집하장 출력
        }
        cout << '\n';
    }
    return 0;
}
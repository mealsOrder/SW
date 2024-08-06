#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 201;
const int INF = 987987987;
int N,M;
int map[MX][MX];
int ans[MX][MX];

void func(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(map[i][j] > map[i][k]+map[k][j]){
                    map[i][j] = map[i][k]+map[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }

    while(M--){
        int a,b,c;
        cin >> a >> b>>c;
        map[a][b] =c;
        map[b][a] =c;
        ans[a][b] = b;
        ans[b][a] = a;
    }
    func();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j){
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

	return 0;
}
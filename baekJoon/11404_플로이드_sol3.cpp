#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
const int INF = 987987987;
int N,M;
int dist[MX][MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }
    int a,b,c;
    for(int i=0;i<M;i++){
        cin >> a>> b>>c;
        dist[a][b] = min(dist[a][b],c);
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    // 출력
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dist[i][j] == INF) dist[i][j]=0;
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
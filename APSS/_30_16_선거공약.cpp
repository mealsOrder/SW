#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 201;
const int INF = 987987987;
int map[MX][MX];
int V;
bool update(int a,int b, int c){
    if(map[a][b]<=c) return false;
    for(int x=0;x<V;x++){
        for(int y=0;y<V;y++){
            map[x][y] = min(map[x][y],min(map[x][a]+ c +map[b][y],
                                          map[x][b]+ c +map[a][y]));
        }
    }
    return true;
}
void floyd(){
    for(int i=0;i<V;i++)map[i][i] = 0;
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        int M,N,ans=0;
        cin >> V>>M>>N;

        //지도 초기화
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                map[i][j] = INF;
            }
        }

        for(int i=0;i<M;i++){
            int a,b,c;
            cin >> a>>b>>c;
            map[a][b] = c;
            map[b][a] = c;
        }

        for(int i=0;i<N;i++){
            int a,b,c;
            cin >> a>>b>>c;
            
            if(!update(a,b,c))ans++;
        }

        cout << ans << '\n';

    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

const int MAX = 101;
char map[MAX][MAX];
int res[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        int N,M;
        cin >> N >>M;
        memset(map,0,sizeof(map));
        memset(res,0,sizeof(res));    
        if(N==0 && M==0) break;
        for(int i=0;i<N;i++) cin >> map[i];

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] == '.')continue;
                else if(map[i][j] == '*')
                    res[i][j] = 1;
                
                for(int d=0;d<8;d++){
                    int nx = i+dx[d];
                    int ny = j+dy[d];

                    if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]=='.'){
                        res[nx][ny] += res[i][j];
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){

                if(map[i][j] == '*') cout << '*';
                else cout << res[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
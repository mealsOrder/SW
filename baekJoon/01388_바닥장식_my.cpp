#include<iostream>
using namespace std;
const int MX = 51;    
// 노가다 풀이...

int N,M;
string map[MX];
bool vis[MX][MX];
int ans;
int dx=1,dy=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    int cnt=1;
    int rnt=0;
    for(int i=0;i<N;i++){
        rnt=0;
        for(int j=0;j<M;j++){
            if(map[i][j] == '-'){
                vis[i][j] = true;
                rnt++;
            }
            else{
                if(rnt != 0){
                    ans += cnt;
                    rnt = 0;
                }
                
            }
        }
        if(rnt != 0) ans += cnt;
    }

    int tnt = 0;
    for(int j=0;j<M;j++){
        int tnt=0;
        for(int i=0;i<N;i++){
            if(map[i][j] == '|'){
                vis[i][j] = true;
                tnt++;
            }
            else{
                if(tnt != 0){
                    ans += cnt;
                    tnt = 0;
                }
                
            }
        }
        if(tnt != 0) ans += cnt;
    }

    cout << ans << '\n'; 
    return 0;
}
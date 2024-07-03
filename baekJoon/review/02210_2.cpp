#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<set>
using namespace std;
const int MX = 6;
set<int>s;
int map[MX][MX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void DFS(int x,int y,int cnt,string c){

    if(cnt == 6){
        s.insert(stoi(c));
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<5 && ny>=0 && ny<5){
            DFS(nx,ny,cnt+1,c+to_string(map[nx][ny]));
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            DFS(i,j,1,to_string(map[i][j]));
        }
    }
    cout << s.size();
    return 0;
}
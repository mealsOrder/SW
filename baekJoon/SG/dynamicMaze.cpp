#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int RMAX = 22;
const int CMAX = 202;
int dx[]={1,0,0}; 
int dy[]={0,-1,1};

int N,M;
string origin[RMAX]; // 원본
string map[RMAX];    
int dist[RMAX][CMAX];
vector<int> v;       

string plusX(string row, int shift){
    string shifted = string(shift,'X') + row;
    shifted.resize(CMAX,'X');
    return shifted;
}

int BFS(int sx, int sy, int ex, int ey){
    for(int i=0;i<N;i++) fill(dist[i],dist[i]+CMAX,-1);

    queue<pair<int,int>>q;
    dist[sx][sy]= 0;
    q.push({sx,sy});

    while(!q.empty()){
        int x =q.front().first;
        int y = q.front().second;
        if(x == ex && y ==ey) return dist[x][y];
        q.pop();

        for(int i=0;i<3;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<CMAX && dist[nx][ny]==-1 && map[nx][ny]=='O'){
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

void back(int row){
    if(row == N){
        int sx=-1,sy=-1,ex=-1,ey=-1;
        for(int j=0;j<CMAX;j++){
            if(map[0][j] == 'S') sx=0, sy=j;
            if(map[N-1][j] == 'F') ex=N-1, ey=j;
        }

        if(sx == -1 || ex == -1) return;

        map[0][sy] = 'O';
        map[N-1][ey] = 'O';

        int res = BFS(sx, sy, ex, ey);
        if(res != -1)v.push_back(res);

        map[0][sy] = 'S';
        map[N-1][ey] = 'F';
        return;
    }

    
    map[row] = plusX(origin[row],0); //요기기
    back(row + 1);
    map[row] = plusX(origin[row],1);
    back(row + 1);
    
    /*
    //오른쪽으로 밀때 행당 한칸이 아닐 경우
    // 요기부터 4줄 주석 처리하고 이거 돌리면 됨
    for(int shift=0; shift<M; shift++){ //각 행당 한 번만 회전 (0~M-1)
        map[row] = plusX(origin[row], shift);
        back(row+1);
    }
    */
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N >> M;
        for(int i=0;i<N;i++) cin >> origin[i];

        v.clear();
        back(0);

        if(v.empty()) cout << -1 << '\n';
        else cout << *min_element(v.begin(),v.end()) << '\n';
    }

    return 0;
}

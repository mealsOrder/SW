#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 101;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N;

vector<int>v;
vector<int>k;
void DFS(int x,int y,int& c){
    // 종료 조건 잘 쓰기!!!
    if(visited[x][y]) return;
    visited[x][y]= true;
    c = c+1;
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[nx][ny]){
            if(map[x][y]==map[nx][ny]){
                DFS(nx,ny,c);
                
            }
            
        }

    }
    
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                int count =0;
                DFS(i,j,count);
                v.push_back(count);
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j] = 0;
            if(map[i][j] == 'G'){
                map[i][j] = 'R';
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                int count =0;
                DFS(i,j,count);
                k.push_back(count);
            }
        }
    }
    cout << v.size()<< " " << k.size();   
    return 0;
}
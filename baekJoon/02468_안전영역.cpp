#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 101;
int map[MAX][MAX];
bool visited[MAX][MAX];
int N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

vector<int>v[MAX];
void init(int x){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(map[i][j] <= x){
                visited[i][j] = true;
            }
            else{
                visited[i][j] = false;
            }
        }
    }
}

void DFS(int x,int y,int& cnt){
    if( visited[x][y])return;
    visited[x][y]=true;
    cnt+=1;

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[nx][ny]){
            DFS(nx,ny,cnt);
        }

    }
    
}

int main() {
    cin >> N;
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    for(int k=0;k<MAX;k++){
        init(k);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]){
                    int count=0;
                    DFS(i,j,count);
                    v[k].push_back(count);
                }
            }
        }
        
    }
    int mx=0;
    for(int i=0;i<MAX;i++){
        if(v[i].size()>mx){
            mx = v[i].size();
        }
    }
    cout << mx << '\n';
    return 0;
}
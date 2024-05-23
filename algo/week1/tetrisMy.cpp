#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 20;

int map[MAX][MAX];

int visited[MAX][MAX];
int C,R;
vector<pair<int,int>>v;
void init(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            visited[i][j] = map[i][j];
        }
    }
}

int isVisited(){
    int result = 0;
    for(int i=0;i<R;i++){
        int count = 0;
        for(int j=0;j<C;j++){
            if(map[i][j]){
                count++;
            }
        }
        if(count == C){
            result++;
        }
    }
    return result;
}

int main() {

    
    cin >> C >> R;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> map[i][j];
        }
    }

    int total = 0;
    int index = 0;
    for(int j=0;j<C;j++ ){
        int now = R-1;

        for(int i=0;i<R;i++){
            if(map[i][j]){
                now = i-1; 
                break;
            }
        }

        if(now<3)continue;

        for(int i=0;i<4;i++){
            map[now - i][j] = 1;
        }
        if(total < isVisited()){
            total = isVisited();
            index = j+1;
        }

        for(int i=0;i<4;i++){
            map[now-i][j]=0;
        }        
    }
    
    cout << index << " " << total << '\n';

    return 0;
}
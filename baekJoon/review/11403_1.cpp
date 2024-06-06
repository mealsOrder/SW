#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MX = 101;
int path[MX][MX];
int N;
void floydWarshall(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(path[i][k] && path[k][j]){
                    path[i][j] = 1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            cin >> a;
            if(a) path[i][j] = 1;
        }
    }
    floydWarshall();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << path[i][j]<< " ";
        }
        cout << '\n';
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<cstring>
using namespace std;

const int MAX = 11;

int map[7][7];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void init(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            map[i][j] = 11;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(map[i][j]<map[i+1][j]&& map[i][j]<map[i-1][j] && 
                map[i][j]<map[i][j+1] && map[i][j]<map[i][j-1]){
                map[i][j] = -1;
            }
        }
    }
    
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(map[i][j]== -1){
                cout << "* ";
            }
            else{
                cout << map[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
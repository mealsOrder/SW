#include<iostream>
#include<queue>
using namespace std;
const int MAX = 11;

int map[MAX][MAX];

int main() {
    
    int N;

    cin >>N;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            map[i][j] = 0;
        }
    }
    for(int t=0;t<N;t++){
        for(int i=0;i<10;i++){
            
            map[t][i] = !map[t][i];
            map[i][t] = !map[i][t];
            
        }
        map[t][t] = !map[t][t];
    }
    

    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << map[i][j]<<" ";

        }
        cout << '\n';
    }


    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
const int MX = 101;
vector<int> adj[MX]; // 인접 리스트
bool path[MX][MX];   // 경로의 존재 여부를 저장하는 배열
int N;

void floydWarshall() {
    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(path[i][k] && path[k][j]) {
                    path[i][j] = true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int edge;
            cin >> edge;
            if(edge) path[i][j] = true; // 간선이 존재하면 경로가 존재함을 표시
        }
    }
    
    floydWarshall(); // 플로이드-워셜 알고리즘 수행
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << path[i][j] << " "; // 각 노드 쌍에 대해 경로의 존재 여부 출력
        }
        cout << '\n';
    }

    return 0;
}

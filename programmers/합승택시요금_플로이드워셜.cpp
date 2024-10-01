#include <string>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 202;
int dist[MAX][MAX];

void init(){
    for(int i = 1;i<=201;i++){
        for(int j = 1;j<=201;j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e8;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    //n 지점 개수 n
    //s 출발 지점
    //a A의 도착지점
    //b b의도착치점
    //fares 예상 요금
    //플로이드,,
    init();
    for(int i = 0;i<fares.size();i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        dist[from][to] = cost;
        dist[to][from] = cost;
        
    }
    
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    
                }
                
            }
        }
    }
    int answer = 1e8;
    for(int i = 1;i<=n;i++){
        answer = min(answer,dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return answer;
}
g
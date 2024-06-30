#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<climits>
#include<deque>
using namespace std;
const int MX = 51;
const int INF = INT_MAX;
string map[MX];
int path[MX][MX];
int N;
/**
 * 플로이드 워셜 풀이
 */
// 친구 사이 거리를 무한대로 초기화
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            path[i][j] = INF; 
        }
    }
}

// 플로이드 워셜 알고리즘을 사용하여 최단 경로를 구함
void floydWarshall(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                // i>k>j 로 거쳐 갈수 있으며(값이 무한대가 아니다)
                // 이 문제의 조건 i,j 값이 같지 않으면...
                if(path[i][k] != INF && path[k][j] != INF && i!=j){
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    init();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 'Y')path[i][j] = 1;
        }
    }

    int mx = 0;
    floydWarshall();
    for(int i=0;i<N;i++){
        int cnt = 0;
        for(int j=0;j<N;j++){
            if(path[i][j] <=2) cnt++;
        }
        mx = max(mx,cnt);
    }
    cout << mx;

    return 0;
}
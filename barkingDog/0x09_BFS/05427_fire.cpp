#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MX = 1001; // 상수 MX를 1001로 설정. 이는 맵의 최대 크기를 의미합니다.
string map[MX]; // 맵을 저장할 문자열 배열 선언
int dist1[MX][MX]; // 불이 번지는 시간을 저장할 배열 선언
int dist2[MX][MX]; // 사람이 이동하는 시간을 저장할 배열 선언
int W,H; // 맵의 너비와 높이를 저장할 변수 선언
int dx[]={0,0,1,-1}; // x축 이동 방향을 저장한 배열. 상, 하, 좌, 우를 의미합니다.
int dy[]={1,-1,0,0}; // y축 이동 방향을 저장한 배열. 상, 하, 좌, 우를 의미합니다.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; // 테스트 케이스의 수를 저장할 변수 선언
    cin >> T; 
    while(T--){ // 각 테스트 케이스에 대해
        bool escape = false; // 탈출 가능 여부를 저장할 변수. 초기값은 false입니다.
        cin>>W>>H; // 맵의 너비와 높이 입력 받기
        // init
        queue<pair<int,int>>q1; // 불의 위치를 저장할 큐 선언
        queue<pair<int,int>>q2; // 사람의 위치를 저장할 큐 선언
        for(int i=0;i<H;i++)map[i].clear(); // 맵 초기화
        for(int i=0;i<H;i++){
            fill(dist1[i],dist1[i]+W,-1); // 불이 번지는 시간을 저장할 배열 초기화
            fill(dist2[i],dist2[i]+W,-1); // 사람이 이동하는 시간을 저장할 배열 초기화
            
        }
        for(int i=0;i<H;i++){
            cin >> map[i]; // 맵 정보 입력 받기
        }

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(map[i][j] == '*'){ // 불의 위치를 찾으면
                    q1.push({i,j}); // 큐에 추가하고
                    dist1[i][j]=0; // 불이 번지는 시간을 0으로 설정
                }
                if(map[i][j] == '@'){ // 사람의 위치를 찾으면
                    q2.push({i,j}); // 큐에 추가하고
                    dist2[i][j] = 0; // 사람이 이동하는 시간을 0으로 설정
                }
            }
        }

        // 불이 번지는 시간을 계산하는 BFS
        while(!q1.empty()){
            int curX = q1.front().first;
            int curY = q1.front().second;
            q1.pop();

            for(int i=0;i<4;i++){
                int nx = curX+dx[i];
                int ny = curY+dy[i];

                if(nx<0||nx>=H||ny<0||ny>=W)continue; // 범위를 벗어나면 continue
                if(dist1[nx][ny]>=0)continue; // 이미 불이 번진 곳이면 continue
                if(map[nx][ny] == '#')continue; // 벽이면 continue
                dist1[nx][ny] = dist1[curX][curY]+1; // 불이 번지는 시간 갱신
                q1.push({nx,ny}); // 큐에 추가
            }   
        }

        // 사람이 이동하는 시간을 계산하는 BFS
        while(!q2.empty() && (!escape)){
            int curX = q2.front().first;
            int curY = q2.front().second;
            q2.pop();

            for(int i=0;i<4;i++){
                int nx = curX+dx[i];
                int ny = curY+dy[i];

                if(nx<0||nx>=H||ny<0||ny>=W){ // 범위를 벗어나면
                    cout << dist2[curX][curY] + 1 << '\n'; // 이동 시간 출력하고
                    escape = true; // 탈출 가능 여부를 true로 설정
                    break;
                }
                if(map[nx][ny] == '#')continue; // 벽이면 continue
                if(dist2[nx][ny] >=0)continue; // 이미 방문한 곳이면 continue
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[curX][curY]+1 )continue; // 불이 먼저 도달하는 곳이면 continue
                
                dist2[nx][ny] = dist2[curX][curY]+1; // 사람이 이동하는 시간 갱신
                q2.push({nx,ny}); // 큐에 추가
            }   
        }
        if(!escape) cout << "IMPOSSIBLE\n"; // 탈출이 불가능하면 "IMPOSSIBLE" 출력
    }
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>

using namespace std;
const int MX = 6;
// 총인원 세로 높이
int T,N,M;

// 각조 초기화
vector<int>arr1 = {20,28,6,10,90};
vector<int>arr2 = {24,18,91,92,93};
vector<int>arr3 = {30,26,22,4,30};
vector<int>arr4 = {1 ,3, 25,9,94};
vector<int>arr5 = {19,7,5,13,96};
vector<int>arr6 = {8,17,97,98,99};

// 방향 벡터
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// 구역 지정 지도
int map[MX][MX];

// 결과
int ans[MX][MX];

// 방문 배열
bool vis[MX][MX];

// x에 따라 칠판 위치 조정
void printTab(int x){
    int aa = 0;
    if(x %2 == 0){
        aa = x/2 -1;
    }
    else{
        aa = x/2 ;
    }
    for(int i=0;i<aa;i++){
        cout << '\t';
    }
}

// 초기화 함수 (테스트 횟수 추가하면 더 넣어야함)
void init(){
    // 초기 벡터
    /*
    arr1 = {20,28,6,10,90};
    arr2 = {24,18,91,92,93};
    arr3 = {30,26,22,4,30};
    arr4 = {1,3,25,9,94,95};
    arr5 = {19,7,5,13,96};
    arr6 = {8,17,97,98,99};
    */

    // 셔플
    mt19937 ag(static_cast<unsigned int>(time(0)));
    shuffle(arr1.begin(),arr1.end(),ag);
    mt19937 bg(static_cast<unsigned int>(time(0)));
    shuffle(arr2.begin(),arr2.end(),bg);
    mt19937 cg(static_cast<unsigned int>(time(0)));
    shuffle(arr3.begin(),arr3.end(),cg);
    mt19937 dg(static_cast<unsigned int>(time(0)));
    shuffle(arr4.begin(),arr4.end(),dg);
    mt19937 eg(static_cast<unsigned int>(time(0)));
    shuffle(arr5.begin(),arr5.end(),eg);
    mt19937 fg(static_cast<unsigned int>(time(0)));
    shuffle(arr6.begin(),arr6.end(),fg);

}

void DFS(int x,int y,vector<int>&a,int num){
    if(vis[x][y])return;

    vis[x][y] = true;
    ans[x][y] = a[0];
    a.erase(a.begin());
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M)continue;
        if(!vis[nx][ny] && map[nx][ny] == num && ans[nx][ny] !=0){
            DFS(nx,ny,a,num);
        }
    }

}


int main(){

    cout << "총 인원 : ";
    cin >> T;

    cout << "세로: ";
    cin >> N;

    cout << "가로: ";
    cin >> M;

    // 구역 나누기
    /*
        1 1 2 2 2
        1 1 1 2 2
        3 3 4 4 4
        3 3 3 4 4
        5 5 6 6 6
        5 5 5 6 6
    */
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    // 구역별 랜덤한 숫자 들어갈 벡터
    vector<int>area;

    // 11 22 33 44 55 66 을 벡터에 넣어줌
    for(int i=1;i<=6;i++){
        area.push_back(i*11);
    }

    // 구역 숫자 셔플
    mt19937 g(static_cast<unsigned int>(time(0)));
    shuffle(area.begin(),area.end(),g);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // map값이 k와 같으면 map을 area[k-1] 값으로 변경
            for(int k=1;k<=6;k++){
                if(map[i][j] == k){
                    map[i][j] = area[k-1];
                }
            }
        }
    }

    init(); // 초기화

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // 해당 좌표를 방문 하지 않았으면
            if(!vis[i][j]){
                if(map[i][j] == 11){
                    DFS(i,j,arr1,11);
                }
                else if(map[i][j] == 22){
                    DFS(i,j,arr2,22);
                }
                else if(map[i][j] == 33){
                    DFS(i,j,arr3,33);
                }
                else if(map[i][j] == 44){
                    DFS(i,j,arr4,44);
                }
                else if(map[i][j] == 55){
                    DFS(i,j,arr5,55);
                }
                else if(map[i][j] == 66){
                    DFS(i,j,arr6,66);
                }
            }
        }
    }


    // 출력
    printTab(M);    
    cout << "  [칠판]  " << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << ans[i][j] << '\t';
        }
        cout << '\n';
    }
    
    return 0;
}
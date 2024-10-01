#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
int T,N,M;

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
int main(){

    cout << "총 인원 : ";
    cin >> T;

    cout << "세로: ";
    cin >> N;

    cout << "가로: ";
    cin >> M;

    // 2차원 벡터 선언 N*M
    vector<vector<int>>v(N,vector<int>(M,0));

    // T까지 숫자 담는 벡터
    vector<int>n;

    for(int i=1;i<=T;i++){
        n.push_back(i);
    }

    // 시간으로 랜덤한 시드 생성
    mt19937 g(static_cast<unsigned int>(time(0)));

    // T까지 숫자를 담은 벡터를 랜덤하게 셔플
    shuffle(n.begin(),n.end(),g);

    int cnt = 0;
    // 2차원 벡터에 랜덤한 숫자 지정 후 cnt 증가
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            v[i][j] = n[cnt];
            cnt++;
        }
    }

    // 출력
    printTab(M);
    cout << "[ 칠판 ]" << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << v[i][j] << '\t';
        }
        cout << '\n';
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >>N;
    vector<int>S(N); // 과일 종류를 저장할 벡터
    for(int i=0;i<N;i++)cin >> S[i];

    // 슬라이딩 윈도우 기법을 위한 변수
    map<int,int>fruitHuru;  // 과일 종류와 개수를 저장할 맵
    int lef=0,rig=0,mxLen = 0; // 왼쪽 포인터, 오른쪽 포인터, 최대길이
    while(rig < N){ // 현재 과일을 맵에 추가
        fruitHuru[S[rig]]++; // 현재 과일을 맵에 추가
        while(fruitHuru.size()>2){ // 과일 종류가 2개를 초과하면
            if(--fruitHuru[S[lef]] == 0){ // 왼쪽 포인터 과일 개수를 줄이고
                fruitHuru.erase(S[lef]); // 개수가 0이 되면 맵에서 제거
            }
            lef++;
        }
        mxLen = max(mxLen, rig - lef + 1);
        rig++;
    }
    cout << mxLen << '\n';
    return 0;
}
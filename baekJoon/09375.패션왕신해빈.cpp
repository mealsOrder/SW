#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>
#include<map>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);  // 입출력 속도 향상을 위한 설정
    cin.tie(0);  // 입출력 속도 향상을 위한 설정
    cout.tie(0);  // 입출력 속도 향상을 위한 설정
    int T;  // 테스트 케이스의 수
    cin >> T;  // 테스트 케이스의 수 입력 받기

    // 각 테스트 케이스에 대해
    while(T--){
        map<string,int>m;  // 의상의 종류를 키로, 그 종류의 의상의 개수를 값으로 가지는 맵
        int N;  // 의상의 개수
        int res = 1;  // 결과값, 1로 초기화
        cin >> N;  // 의상의 개수 입력 받기

        // 각 의상에 대해
        for(int i=0;i<N;i++){
            string a,b;  // 의상의 이름과 종류
            cin >> a >> b;  // 의상의 이름과 종류 입력 받기
            m[b]++;  // 해당 종류의 의상의 개수 증가
        }

        // 각 종류의 의상에 대해
        for(auto i : m){
            // 해당 종류의 의상을 입지 않는 경우를 포함하여 (i.second + 1)을 곱함
            res *= (i.second + 1);
        }
        // 아무것도 입지 않는 경우를 제외하기 위해 1을 뺌
        cout << res - 1 << '\n';
    }

    return 0;
}

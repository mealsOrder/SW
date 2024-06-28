#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/**
 * 중복되는 수열을 여러번 출력하면 안되며,
 * 각 수열은 공백으로 구분해서 출력
 * 수열은 사전 순으로 증가하는 순서로 출력
 */

int N,M;
vector<int>v;// 선택한 숫자들을 저장할 벡터
// 백트래킹 함수
void back(int x){
    // 선택한 숫자의 개수가 M개가 되면
    if( v.size() == M){
        // 선택한 숫자들을 출력하고 함수 종료
        for(int num:v) cout << num << " ";
        cout << '\n';
        return ;
    }

    // x부터 N까지의 숫자 중에서
    for(int i=x;i<=N;i++){
        v.push_back(i); // 현재 선택된 숫자를 벡터 v 에 추가
        back(i+1); // 다음 숫자 선택을 위해 재귀 호출 (i+1)
        v.pop_back(); // 방금 추가했던 숫자를 v 벡터에서 제거
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M;
    
    back(1); // 백트래킹 함수 호출 (1부터 시작!)
    return 0;
}
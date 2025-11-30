#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;
/**
 * @brief [문제]{0,1,2,3}의 모든 부분집합을 비트마스킹을 이용해 출력하는 함수
 * @author mealsOrder
 * @date 2025-05-19
 */
void func(){
    for(int tmp=0;tmp<16;tmp++){
        cout << '(';
        for(int i=0;i<4;i++){
            if(tmp & (1 << i)) cout <<i;
        }
        cout << ')' << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    func();

    return 0;
}

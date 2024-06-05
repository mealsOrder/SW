#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/**
 * 비트마스크란?
 * 컴퓨터는 내부적으로 모든 자료를 이진수(비트)로 처리한다.
 * 이런 컴퓨터의 연산방식을 이용한, 정수의 이진수 표현을 활용하여
 * 문제를 해결하는 기법
 * 
 * 비트(Bit)란?
 * 비트는 이진수(0,1로 구성된 수) 컴퓨터에서 사용하는 데이터의 최소 단위
 * 
 * 비트마스크의 장점
 * (1) 수행 시간이 빠르다 >> 대부분 O(1)의 시간복잡도를 가짐
 *     - 특정 원소의 존재여부판단시 선형탐색할 필요없이 and연산결과가 0보다 큰지 검사
 * (2) 코드가 짧다
 *     - 집합연산들을 비트 연산자로 작성하기 때문에 코드가 간결해 진다
 * (3) 메모리 사용량이 적다.
 *     - bit가 10개인 경우 각 비트는 2가지 경우를 가지기 때문에
 *       2^10의 경우의 수를 10 bit의 이진수 하나로 표현이 가능하다.
 * 
 * 비트 연산 종류
 * A    B    ~A     A&B     A|B     A^B(xor)
 * 0    0    1      0       0       0
 * 0    1    1      0       1       1
 * 1    0    0      0       1       1
 * 1    1    0      1       1       0     
 * 
 * https://velog.io/@alkwen0996/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B9%84%ED%8A%B8%EB%A7%88%EC%8A%A4%ED%81%AC
 *      
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin >>M;

    int S = 0;
    while(M--){
        string op;
        cin >> op;

        if(op == "add"){
            int x;
            cin >> x;
            S |= (1 << (x-1)); 
        }
        else if(op == "remove"){
            int x;
            cin >> x;
            S &= ~(1 << (x-1));
        }
        else if(op == "check"){
            int x;
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';
        }
        else if(op=="toggle"){
            int x;
            cin >>x;
            S ^= (1 << (x-1));
        }
        else if(op == "all"){
            S = (1<<20) - 1;
        }
        else if(op == "empty"){
            S = 0;
        }
    }
    return  0;
}
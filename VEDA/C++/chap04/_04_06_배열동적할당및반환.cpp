#include<iostream>
using namespace std;

/**
 * 사용자로부터 정수의 개수를 입력 받아 
 * 배열을 동적 할당 받고 
 * 하나씩 정수를 입력받은 후 합을 출력하는 프로그램
 */

int main(){
    int N;
    cout << "입력할 정수의 개수?";
    cin >> N;

    if(N<=0) return 0;

    int *p = new int[N]; // n개의 정수 배열 동적 할당
    if(!p){
        cout << "메모리를 할당할 수 없습니다.\n";
        return 0;
    } 

    for(int i=0;i<N;i++){
        cout << i+1 << "번쩨 정수: ";
        cin >> p[i]; // *(p+i) 랑 동치
    }

    int sum = 0;
    double avg = 0;
    for(int i=0;i<N;i++){
        sum += p[i]; // *(p+i) 랑 동치 
    }
    avg = (double)sum/N;
    cout << "합계: " << sum << '\n';
    cout << "평균: " << avg << '\n';

    delete [] p; // 배열 메모리 반환
    return 0;
}
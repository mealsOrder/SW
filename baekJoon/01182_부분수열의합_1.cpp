#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 22;
int arr[MAX];
int N,S;
int cnt=0;
// 0                        0
// 1              0                 -7
// 2        0         -3        -7       -10 
// 3    0    -2    -3    -5  -7  -9   -10   -12
// 4  ...
// ��� ����� �� :�ƹ��͵� ���� ����~ �����ڰ� �� ���� 
// 16 >>
// if sum == S �ع����� S�� 0 �϶� �������� ��쵵 ���� -1����� ������
// if sum+arr[idx] == S �ϸ� �� �� ������??? ��...
void f(int idx,int sum){
    // ��� ���� �� ���ϸ� ����
    if(idx == N) return;
    // ���ݱ����� �տ��� ���� �ε����� ���� ���Ѱ��� ��ǥ���̸� 1����
    if(sum+arr[idx] == S) cnt++;
    
    // ���� �ε����� ���� �������� ����
    f(idx+1,sum); 
    // ���� �ε����� ���� ����
    f(idx+1,sum + arr[idx]);
}

int main() {
    
    
    cin >>N>>S;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    cnt= 0;
    f(0,0);
    cout << cnt;
    return 0;
}
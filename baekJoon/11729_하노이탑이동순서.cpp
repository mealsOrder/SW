#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

void func(int n,int a,int b){
    // 0으로 하고 아래 출력 주석처리 하면 같은 결과 나오는거 같은데 맞는지 모르겠네?
    if(n==1){ 
        cout << a << ' ' << b << '\n';
        return;
    }

    func(n-1,a,6-a-b);
    cout << a << ' ' << b << '\n';
    func(n-1,6-a-b,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cout << (int)pow(2,N)-1 << '\n';
    func(N,1,3);
    return 0;
}
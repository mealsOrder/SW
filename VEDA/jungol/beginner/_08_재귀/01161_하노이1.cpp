#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void movePrint(int n,int from,int to){
    cout << n << " : " << from << " -> " << to << '\n';
}
// from : 출발, to : 목표, sub : 보조
void func(int n, int from,int to,int sub){
    if(n == 1){
        movePrint(1,from,to);
        return;
    }
    // n-1 개의 원판을 보조 기둥으로 이동
    func(n-1,from,sub,to);
    movePrint(n,from,to);
    // 보조 기둥에 있는 n-1개의 원판을 목표 기둥으로 이동
    func(n-1,sub,to,from);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    func(N,1,3,2);

    return 0;
}
#include<iostream>

using namespace std;
int func1(int x){
    if(x== 0) return 0;
    else return x + func1(x-1);
}
void func2(int x){
    if(x == 0)return;
    cout << x << " ";
    func2(x-1);
}
int main(){
    int N;
    cin >> N;
    int ans = func1(N);
    cout << ans <<'\n';
    func2(N);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;

int N;
int cnt=0;
bool check1[MX];
bool check2[MX];
bool check3[MX];
void func(int x){
    if(x==N){
        cnt++;
        return;
    }
    for(int i=0;i<N;i++){
        if(check1[i] || check2[i+x] || check3[x-i+N-1])continue;

        check1[i]=1;
        check2[i+x]=1;
        check3[x-i+N-1]=1;
        func(x+1);
        check1[i]=0;
        check2[i+x]=0;
        check3[x-i+N-1]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}
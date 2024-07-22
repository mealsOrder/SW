#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N,M;
vector<int>arr;
void func(int k,int sum){
    if(k==N){
        if(sum == M){
            for(int i=0;i<N;i++){
                cout << arr[i] <<' ';
            }
            cout << '\n';
            
        }
        return;
    }
    for(int i=1;i<=6;i++){
        arr.push_back(i);
        func(k+1,sum+i);
        arr.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0,0);


    return 0;
}
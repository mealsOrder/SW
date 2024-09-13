#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set<int>s;
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    for(auto d : s){
        cout << d << " ";
    }
    return 0;
}
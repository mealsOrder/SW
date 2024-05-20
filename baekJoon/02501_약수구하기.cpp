#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int cnt;
int main() {
    
    int N,K;
    cin >> N>>K;
    for(int i=1;i<=N;i++){
        if(N%i == 0){
            v.push_back(i);
            cnt ++;
        }
        
    }
    sort(v.begin(),v.end());
    
    if(cnt < K){
        cout << '0' << endl;
    }
    else{
        cout << v[K-1];
    }

    return 0;
}
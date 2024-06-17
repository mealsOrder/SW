#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >>T;
    while(T--){
        map<string,int>m;
        int N;
        cin >> N;
        int res = 1;
        for(int i=0;i<N;i++){
            string a,b;
            cin >> a >> b;
            m[b]++;    
        }
        
        for(auto k:m){
            res *= (k.second+1);
        }
        cout << res-1 << '\n';
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        int N,M;
        cin >> N >> M;
        
        int a,b;
        while(M--){
            cin >> a >> b;
        }
        cout << N-1 << '\n';
    }
    
    return 0;
}
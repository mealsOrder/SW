#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int N;
    cin >> N;
    vector<int>v(N+1);
    vector<int>pre(N+1);
    v[1] = 0;
    for(int i=2;i<=N;i++){
        v[i] = v[i-1] + 1;
        pre[i] = i -1;
        if(i%2 == 0 && v[i] > v[i/2]+1 ){
            v[i] = v[i/2]+1;
            pre[i] = i/2;
        }
        if(i%3==0 && v[i] > v[i/3]+1){
            v[i] = v[i/3]+1;
            pre[i] = i/3;
        }
    }
    cout << v[N] << '\n';
    
    while(N){
        cout << N << " ";
        N = pre[N];
    }
	return 0;
}

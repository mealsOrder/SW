#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

long long N,X;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >>N >> X;
    if(N>X)swap(N,X);

    if(N == X || X-N == 1){
        cout << 0;
    }
    else{
        int len = X-N-1;
        cout << len << '\n';
        for(long long i=N+1;i<X;i++){
            cout << i << " ";
        }

    }
    

	return 0;
}
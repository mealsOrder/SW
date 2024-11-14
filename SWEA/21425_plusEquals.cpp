#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 100001;
int A,B,N,C,D;
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        A=0,B=0,N=0;
        int ans = 0;
        cin >> A >> B >> N;
        C=0,D=0;
        while(true){
            C = min(A,B);
            D = max(A,B);
            
            A = C;
            B = D;
            A += B;
            ans ++;
            if((A > N) || (B > N)) break;
        }
        
        cout << ans << '\n';
    }
		

    return 0;
}
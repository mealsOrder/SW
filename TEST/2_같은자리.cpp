#include<iostream>
#include<cstring>
using namespace std;
const int MX = 1002;
int a[MX];
int b[MX];
int N,ans;
int pre;
int dp[MX];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        ans = 0;
        cin >> N;

        fill(a,a+N+1,0);
        fill(b,b+N+1,0);
        
        for(int i=0;i<N;i++) cin >> a[i];
        for(int i=0;i<N;i++) cin >> b[i];

        for(int i=0;i<N;i++){
            
            for(int j=i;j<N;j++){
                if(a[i] == b[j] ){
                    pre = j -a;
                    ans ++;
                    break;
                }
                else if( a[i] != b[j] && )
                else{
                    ans = 1;
                    
                }
            }
        }

        cout << "#" << t << " " << ans << '\n';
    }



    return 0;
}
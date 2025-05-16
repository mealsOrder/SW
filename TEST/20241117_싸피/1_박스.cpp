#include<iostream>
#include<cstring>
using namespace std;
const int MX = 502;
int arr[MX];
int N,D,X, ans;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        
        ans = 0;
        cin >> N >> D >> X;
        fill(arr,arr+N+1,0);

        for(int i=0;i<N;i++){
            cin >> arr[i];
        }

        int mul = arr[D-1];
        if( mul == 0){
            if(D < X) ans = X-D;
            else if( D > X) ans = N- (D-X);
        }
        else{
            if( D == X) ans = mul * N;
            else if ( D < X ) ans = mul*N + (X-D);
            else if ( D > X ) ans = mul*N + N-(D-X);
        }
        
        cout << "#" << t << " " << ans << '\n';
    }



    return 0;
}
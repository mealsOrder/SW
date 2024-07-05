#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int X,Y;
    cin >> X >> Y;
    long long int Z = (floor((double)Y/X * 100));
    long long int ans = LONG_LONG_MAX;
    long long int lef=1,rig = X;
    if( Z>= 99 ){
        cout << "-1\n";
        return 0;
    }
    
    while(lef<=rig){
        long long int mid = (lef+rig)/2;
        long long int chg = (floor((double)(Y+mid)/(X+mid) * 100));

        if( chg > Z){
            rig = mid-1;
            ans = min(ans,mid);
        }
        else{
            lef = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}
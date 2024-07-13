#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;
const int MX = 1000000000;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long X,Y,Z;
    cin >> X >> Y;
    Z = (Y*100/X);
    if( Z>= 99 ){
        cout << "-1\n";
        return 0;
    }
    int lef = 0,rig = MX;

    while(lef<=rig){
        int mid = (lef+rig)/2;
        int chg = (Y+mid)*100 / (X+mid);

        if( chg > Z){
            rig = mid-1;
        }
        else{
            lef = mid+1;
        }
    }
    cout << lef << '\n';
    return 0;
}
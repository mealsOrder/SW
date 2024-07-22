#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N,M;
    int ans=0,i=1;
    cin >> N >> M;

    while(M){
        int res = N* (M%10);
        cout << res << '\n';
        M /= 10;
        ans += res*(int)pow(10,i-1);
        i++;
    }
    cout << ans;
	return 0;
}
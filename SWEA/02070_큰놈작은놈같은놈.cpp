#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int A,B;
        char ans;
        cin >> A >> B;

        if(A>B) ans = '>';
        else if(A == B) ans ='=';
        else ans = '<';
        
        cout << '#' << t << ' ' << ans << '\n';
    }
		

    return 0;
}
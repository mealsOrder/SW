#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int a, b;
        cin >> a >> b;

        if( a == 0 && b == 0) break;
        if(a > b) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
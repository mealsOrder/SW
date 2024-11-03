#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,B;
    string ans="";
    cin >> N >> B;

    while(N>0){
        int temp = N%B;
        if(0 <=temp && temp <=9) ans += (temp+'0');
        else ans += (temp-10 + 'A');
        N /=B;
    }
    for(int i=ans.length()-1;i>=0;i--){
        cout << ans[i];
    }


    return 0;
}
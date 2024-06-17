#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string in;
    cin >> in;
    int res=1;
    char pre = 0;
    for(char c : in){
        if(c == 'c'){
            if( pre == 'c') res *= 25;
            else res *= 26;
        }
        // c == 'd'
        else{
            if( pre == 'd') res *= 9;
            else res *= 10;
        }
        pre = c;
    }
    cout << res << '\n';
    return 0;
}
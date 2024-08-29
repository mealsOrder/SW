#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string str;
    int o=0, z=0;
    cin >> str;
    char pre = 'k';
    for(char s : str){
        
        if(s == '1' && pre != s ){
            o++;
        }
        else if(s == '0' && pre != s){
            z++;
        }
        pre = s;
    }
    cout << min(z,o);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        string input;
        cin >> input;
        list<char>L;
        auto curser = L.begin();

        for(auto s:input){
            if(s == '<'){
                if(curser != L.begin()) curser--;
            }
            else if(s == '>'){
                if(curser != L.end()) curser++;
            }
            else if(s == '-'){
                if(curser != L.begin()){
                    curser--;
                    curser = L.erase(curser);
                }
            }else{
                //curser++;
                L.insert(curser,s);
            }
            
        }
        for(auto k:L)cout << k;
        cout << '\n';
    }
    return 0;
}
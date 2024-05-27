#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >>T;
    while(T--){
        list<char>L = {};

        string a;
        list<char>::iterator cursor = L.begin();

        cin >> a;
        for(auto c : a){
            if(c == '<'){
                if(cursor != L.begin()) cursor--;
            }
            else if(c == '>'){
                if(cursor != L.end()) cursor++;
            }
            else if(c == '-'){
                if(cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else{
                L.insert(cursor,c);
            }
        }
        
        for(auto i : L) cout << i;
        cout << '\n';
    }


	return 0;
}
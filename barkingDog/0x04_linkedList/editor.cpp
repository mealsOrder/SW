#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string init;
    cin >> init;
    list<char>L;
    for(auto c : init) L.push_back(c);
    auto cursor = L.end();
    int N;
    cin >> N;

    while(N--){
        char op;
        cin >> op;

        if(op == 'P'){
            char add;
            cin >> add;
            L.insert(cursor,add);
        }
        else if(op=='L'){
            if(cursor != L.begin()) cursor--;
        }
        else if(op=='D'){
            if(cursor != L.end()) cursor++;
        }
        else{
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }

    }

    for(auto i : L)cout << i;
	return 0;
}
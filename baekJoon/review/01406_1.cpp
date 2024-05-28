#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    list<char>L;
    string init;
    cin >> init;
    for(auto t:init)L.push_back(t);
    auto cursor = L.end();
    int N;
    cin >>N;

    while(N--){
        char op;
        cin >> op;
        if(op == 'P'){
            char k;
            cin >> k;
            //cursor--;
            L.insert(cursor,k);
        }
        else if(op == 'L'){
            if(cursor != L.begin())cursor--;
        }
        else if(op == 'D'){
            if(cursor != L.end())cursor++;
        }
        else{
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for(auto y : L) cout << y;
    return 0;
}
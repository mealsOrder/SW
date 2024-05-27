#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char>L;
    string init;
    cin >> init;
    for(auto t:init) L.push_back(t);
    auto cursor = L.end();

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        char op;
        cin >> op;
        if(op == 'P'){
            char p;
            cin >> p;
            L.insert(cursor,p);
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

    for(auto i: L){
        cout << i;
    }
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    list<char>s;
        
    string input;
    cin >> input;
    for(auto a : input) s.push_back(a);
    auto t = s.end();
    int N;
    cin >>N;

    for(int i=0;i<N;i++){
        char op;
        cin >> op;
        if(op == 'P'){
            char x;
            cin >> x;
            s.insert(t,x);
        }
        else if(op == 'L'){
            if(t != s.begin())t--;
        }
        else if(op == 'D'){
            if(t != s.end())t++;
        }
        else{ // B일경우
            if(t != s.begin()){
                t--;
                t = s.erase(t);
            }
        }
    }

    for(auto r : s) cout << r;

    return 0;
}
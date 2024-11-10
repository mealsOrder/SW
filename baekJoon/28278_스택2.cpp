#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

stack<int>s;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int N;
    cin >> N;

    while(N--){
        int op;
        cin >> op;
        if(op == 1){
            int a;
            cin >> a;
            s.push(a);
        }
        else if(op == 2){
            if(s.empty()) cout << -1 << '\n';
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(op == 3){
            cout << s.size() << '\n';
        }
        else if(op == 4){
            if(!s.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else{
            if(!s.empty()){
                cout << s.top() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    stack<int>s;
    stack<pair<int,int>>k; // op, num;
    while(Q--){
        int op;
        cin >> op;
        
        if(op == 1){
            int i;
            cin >> i;
            s.push(i);
            k.push({1,i});
        }
        else if(op == 2){
            if(!s.empty()){
                int num = s.top();
                s.pop();
                k.push({2,num});
            }
        }
        else if(op == 3){
            int j;
            cin >> j;
            while(j--&&!k.empty()){
                int op = k.top().first;
                int re = k.top().second;
                k.pop();
                if(op == 1) s.pop();
                else if(op==2) s.push(re);
            }
        }
        else if(op == 4){
            cout << s.size() << '\n';
        }    
        else if(op == 5){
            if(!s.empty()){
                cout << s.top() << '\n';
            }
            else cout << -1 << '\n';
        }            
        
    }
    return 0;
}

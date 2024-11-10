#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

deque<int>d;
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
            d.push_front(a);
        }
        else if(op == 2){
            int a;
            cin >> a;
            d.push_back(a);
        }
        else if(op == 3){
            if(!d.empty()){
                cout << d.front() << '\n';
                d.pop_front();
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(op == 4){
            if(!d.empty()){
                cout << d.back() << '\n';
                d.pop_back();
            }
            else cout << -1 << '\n';
        }
        else if(op == 5){
            cout << d.size() << '\n';
        }
        else if(op == 6){
            if(!d.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if(op == 7){
            if(!d.empty()){
                cout << d.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else{
            if(!d.empty()){
                cout << d.back() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}

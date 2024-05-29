#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    deque<int>dq;
    int N;
    cin >> N;
    while(N--){
        string op;
        cin >> op;

        if(op == "push_back"){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if(op == "push_front"){
            int a;
            cin >> a;
            dq.push_front(a);
        }else if(op=="front"){
            if(dq.empty()) cout <<"-1\n";
            else cout << dq.front()<<'\n';
        }else if(op=="back"){
            if(dq.empty()) cout <<"-1\n";
            else cout << dq.back()<<'\n';
        }else if(op=="size"){
            cout << dq.size()<<'\n';
        }else if(op=="empty"){
            cout <<dq.empty() <<'\n';
        }else if(op == "pop_front"){
            if(dq.empty()) cout << "-1\n";
            else {
                cout <<dq.front() << '\n';
                dq.pop_front();
            }
        }
        else{ // (op == "pop_back")
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
    }
    return 0;
}
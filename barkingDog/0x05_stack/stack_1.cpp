#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

stack<int>s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string op;
        cin >> op;
        if(op.compare("push")==0){
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op.compare("top")==0){
            if(s.empty()){
                cout << "-1\n";
            }
            else cout << s.top() << '\n';
        }
        else if(op.compare("size")==0){
            cout << s.size()<<'\n';
        }
        else if(op.compare("empty") == 0){
            cout << (int)s.empty() << "\n";
        }
        else if(op.compare("pop") == 0){
            if(s.empty()) cout << "-1\n";
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
    }
	return 0;
}
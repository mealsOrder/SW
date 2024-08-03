#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 10001;
int s[MX];
int top = -1;
int empty(){
    if(top == -1) return 1;
    else return 0;
}
void push(int x){
    s[++top] = x;
}
int pop(){
    if(empty())return -1;
    return s[top--];
}
int size(){
    return top+1;
}

int topN(){
    if(empty()) return -1;
    return s[top];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string op;
        cin >>op;

        if(op.compare("push") == 0){
            int num;
            cin >> num;
            push(num);
        }
        else if(op.compare("pop") == 0){
            cout << pop() << '\n';
        }
        else if(op.compare("size") == 0){
            cout << size() << '\n';
        }
        else if(op.compare("top") == 0){
            cout << topN() << '\n';
        }
        else if(op.compare("empty") == 0){
            cout << empty() << '\n';
        }

    }
    return 0;
}

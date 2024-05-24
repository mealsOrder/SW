#include<iostream>

using namespace std;
const int MAX = 10001;

class Queue{
    // 맴버 변수
    public:
    int queue[MAX];
    int begin=0;
    int end=0;

    // 생성자
    Queue(){}

    // x를 넣는 메서드
    void push(int x){
        queue[end] = x;
        end+=1;
    }
    // 비어있으면 1, 아니면 0 반환
    bool empty(){
        if(begin == end){
            return true;
        }else{
            return false;
        }
    }
    // 맨앞의 값을 반환, 비어있다면 -1
    int front(){
        if(empty()){
            return -1;
        }
        return queue[begin];
    }
    // 맨뒤 값을 반환, 비어있다면 -1
    int back(){
        if(empty()){
            return -1;
        }
        return queue[end-1];
    }
    // 크기를 반환
    int size(){
        return end - begin;
    }
    // 맨앞의 숫자를 지우고 그 수를 반환
    int pop(){
        if(empty()){
            return -1;
        }
        int out = queue[begin];
        queue[begin]=0;
        begin+=1;
        return out;
    }

};

int main() {
    
    int N;
    cin >>N;
    Queue q;
    for(int i=0;i<N;i++){
        string op;
        

        cin >> op;

        if(op == "push"){
            int input;
            cin >> input;
            q.push(input);
        }
        else if(op == "pop"){
            cout << q.pop() << "\n";
        }
        else if(op == "empty"){
            cout << q.empty() << "\n";
        }
        else if(op == "front"){
            cout << q.front() << "\n";
        }
        else if(op == "back"){
            cout << q.back() << "\n";
        }
        else if(op == "size"){
            cout << q.size() << "\n";
        }

    }

    return 0;
}
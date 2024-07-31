#include<iostream>
using namespace std;

template <class T>
class MyStack{
    int top;
    T data[100];
public:
    MyStack();
    void push(T a);
    T pop();
};

template <class T>
MyStack<T>::MyStack(){
    top = -1;
}

template <class T>
void MyStack<T>::push(T a){
    if(top == 99){
        cout << "stack full\n";
        return;
    }
    data[++top] = a;
}

template <class T>
T MyStack<T>::pop(){
    T res;
    if(top == -1){
        cout << "stack empty\n";
        return 0;
    }
    res = data[top--];
    return res;
}


int main(){
    MyStack<int> iStack;    // int 만 저장할 수 있는 스택
    iStack.push(3);
    cout << iStack.pop() << '\n';

    MyStack<double> dStack;    // double 만 저장할 수 있는 스택
    dStack.push(3.5);
    cout << dStack.pop() << '\n';

    MyStack<char> *p = new MyStack<char>(); // double 만 저장할 수 있는 스택
    p->push('a');
    cout << p->pop() << '\n';
    delete p;

    return 0;
}
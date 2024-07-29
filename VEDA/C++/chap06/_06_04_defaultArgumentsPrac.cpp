#include<iostream>

using namespace std;

void f(char c = ' ',int line=1){
    for(int i=0;i<line;i++){
        for(int j=0;j<10;j++){
            cout << c;
        }
        cout << '\n';
    }
}

int main(){
    f();
    f('%');
    f('@',4);

    // 포인터 변수의 디폴트 값
    // 포인터 변수를 디폴트 매개 변수로 선언할 때 다음과 같이 디폴트 값을 줄수 있음
    // void f(int *p = NULL);
    // void g(int x[] = NULL);
    // void g(const char *s = "hello");

    return 0;   
}
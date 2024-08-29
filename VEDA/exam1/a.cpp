#include<iostream>
using namespace std;
int main(){
    int a = 1;

    {
        int a = 3;
    }
    cout << a << '\n';    
    return 0;
}
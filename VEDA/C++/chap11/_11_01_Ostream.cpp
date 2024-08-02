#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout.put('H');
    cout.put('i');
    cout.put(33); // !
    cout.put('\n');

    cout.put('C').put('+').put('+').put(' ');

    char str[] = "I hate programming";
    cout.write(str,6);
    return 0;
}
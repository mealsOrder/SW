#include<iostream>

using namespace std;

void star(int a =5){
    for(int i=0;i<a;i++)cout << '*';
    cout << '\n';
}
void msg(int id, string txt = ""){
    cout << id << " " << txt << '\n';
}
int main(){

    star();
    star(10);

    msg(10);
    msg(10,"hell");
    return 0;   
}
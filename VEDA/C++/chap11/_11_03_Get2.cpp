#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char cmd[80];
    cout << "cin.get(char*,int)\n";
    while(true){
        cout << "if  input exit, exit>> ";
        cin.get(cmd,80);
        if(strcmp(cmd,"exit") == 0){
            cout << "exit";
            return 0;
        }
        else
            cin.ignore(1); // 버퍼에 남아있는 Enter키 제거
    }
    return 0;
}
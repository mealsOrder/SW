#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char line[80];
    cout << "cin.getline()\n";
    cout << "if  input exit, exit>> ";
    int no = 1;
    while(true){
        cout << "라인 " << no << " >> ";
        cin.getline(line,80);
        if(strcmp(line,"exit") == 0)break;
        cout << "echo --> ";
        cout << line << '\n';
        no++;
    }
    return 0;
}
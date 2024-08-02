#include<iostream>
#include<fstream>
using namespace std;

int main(){

    
    ifstream fin;
    fin.open("D:\\hub\\SW\\VEDA\\C++\\chap12\\a.txt");
    if(!fin){
        cout << "파일을 열수 없다!";
        return 0;
    }
    char name[10],dept[10];
    int sid;

    fin >> name;
    fin >> sid;
    fin >> dept;
    
    cout << name << '\n';
    cout << sid << '\n';
    cout << dept << '\n';
    
    fin.close();
    return 0;   

}
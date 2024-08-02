#include<iostream>
#include<fstream>
using namespace std;

int main(){

    char name[10],dept[10];
    int sid;

    cout << "이름>>";
    cin >> name;
    cout << "학번>>";
    cin >> sid;
    cout << "학과>>";
    cin >> dept;

    ofstream fout("D:\\hub\\SW\\VEDA\\C++\\chap12\\a.txt");
    if(!fout){
        cout << "D:\\hub\\SW\\VEDA\\C++\\chap12\\a.txt 파일을 열수 없음!";
        return 0;
    }

    fout << name << '\n';
    fout << sid << '\n';
    fout << dept << '\n';
    
    fout.close();
    return 0;   

}
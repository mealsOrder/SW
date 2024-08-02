#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    ofstream fout;
    fout.open("D:\\hub\\SW\\VEDA\\C++\\chap12\\b.txt");
    if(!fout){
        cout << "파일을 열수 없다!";
        return 0;
    }
    char tel[100],name[100];

    cin >> tel;
    cin >> name;
    
    fout << tel << '\n';
    fout << name << '\n';
    
    fout.close();
    return 0;   

}
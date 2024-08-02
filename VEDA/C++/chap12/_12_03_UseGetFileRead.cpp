#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    const char* file = "c:\\windows\\system.ini";
    ifstream fin(file);
    if(!fin){
        cout << file << "열거오류\n";
        return 0;
    }
    int cnt =0;
    int c;
    while((c=fin.get())!=EOF){
        cout << (char)c;
        cnt++;
    }
    cout << "읽은 바이트 수는 " << cnt << '\n';
    fin.close();
    return 0;   

}
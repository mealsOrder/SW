#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

istream& inpto(istream& is){
    cout << "누가 이쁨?";
    return is;
}

int main(){
    string ans;
    cin >> inpto >> ans;
    cout << "이쁜사람" << ans << '\n';
    return 0;   

}
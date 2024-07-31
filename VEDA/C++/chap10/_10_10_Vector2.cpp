#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string>v;
    string name;

    cout << "input 5 name\n";
    for(int i=0;i<5;i++){
        cout << i+1 << ">>";
        cin >> name;
        v.push_back(name);
    }
    name = v.at(0);
    for(int i=1;i<v.size();i++){
        if(name < v[i]){
            name = v[i];
        }
    }
    cout << name << '\n';
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int>v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int elem:v)cout<< elem << " ";
    cout <<'\n';

    v[0] = 10;
    int m = v[2];
    v.at(2) = 5;
    for(int elem:v)cout<< elem << " ";
    cout << '\n';
    return 0;
}
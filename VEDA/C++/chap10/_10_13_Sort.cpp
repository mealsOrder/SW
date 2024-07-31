#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool big(int a,int b){
    if(a>b) return a>b;
    else return a<b;
}

int main(){
    vector<int>v;

    cout << "input 5 num>>";
    for(int i=0;i<5;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout << *it << " ";
    }
    cout << '\n';
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int square(int x){return x*x;}

int main(){

    auto c ='a';
    auto pi = 3.14;
    auto ten = 10;
    auto *p = &ten;
    cout << c << pi << ten << *p << '\n';

    auto res = square(3);
    cout << *p << " " << res << '\n';

    vector<int> v = {1,2,3,4,5};
    vector<int>::iterator it;

    for(auto it = v.begin();it!=v.end();it++){
        cout << *it << " ";
    }
    return 0;
}
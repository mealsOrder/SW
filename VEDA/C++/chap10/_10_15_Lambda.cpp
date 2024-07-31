#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(int n){
    cout << n << " ";
}

int main(){
    [](int x,int y){cout << x+y;};
    [](int x,int y) -> int {return x+y;};
    [](int x,int y){cout << x+y;}(2,3);
    // x,y를 합하는 람다식
    [](int x,int y){cout << "\n합은 " << x+y; }(2,3);
    cout << '\n';
    auto love = [](string a,string b){
        cout << a <<"보다 " << b <<"이 좋아\n";
    };

    love("너","돈");
    love("냉면","라면");

    double pi = 3.14;
    auto calc = [pi](int r) -> double {return pi*r*r;};
    cout << calc(3)<<'\n';

    int sum = 0;
    [&sum](int x,int y){sum = x+y;}(2,3);

    cout << "합은 " << sum << '\n';

    vector<int>v = {1,2,3,4,5};

    for_each(v.begin(),v.end(),print);
    cout << '\n';
    for_each(v.begin(),v.end(),[](int n){cout << n << " ";} );

    return 0;
}
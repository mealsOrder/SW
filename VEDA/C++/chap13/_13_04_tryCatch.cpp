#include<iostream>
using namespace std;

int main(){
    int n, sum,avg;

    while(true){
        cout << "sum>>";
        cin >> sum;
        cout << "num>>";
        cin >> n;
        try{
            if(n<=0) throw n;
            else avg = sum/n;
        }
        catch(int x){
            cout << "exception! Can't be divided with " << x << '\n';
            avg = 0;
            cout << '\n';
            continue;
        }
        cout << "avg = " << avg << '\n';
    }
    return 0;
}
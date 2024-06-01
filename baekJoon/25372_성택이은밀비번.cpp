#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        string a;
        cin >> a;
        if(a.length() >=6 && a.length()<=9) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
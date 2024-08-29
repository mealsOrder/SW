#include<iostream>
#include<algorithm>
using namespace std;
const int MX = 1001;
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        string str ="";
        cin >> str;
        int n = str.length();
        cout << str[0] << str[n-1] << '\n';
    }

    return 0;
}
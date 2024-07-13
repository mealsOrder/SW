#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 51;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    string str[MX];
    for(int i=0;i<N;i++){
        cin >> str[i];
    }

    char ch;

    for(int i=0;i<str[0].length();i++){
        ch = str[0][i];
        for(int j=0;j<N;j++){
            if( ch != str[j][i]){
                ch = '?';
                break;
            }
        }
        cout << ch;
    }
    return 0;
}
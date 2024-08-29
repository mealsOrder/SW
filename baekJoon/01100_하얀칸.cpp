#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 8;
string map[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<MX;i++){
        cin >> map[i];
    }
    int cnt=0;
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            if(map[i][j] == 'F'){
                if(i%2==0 && j%2==0) cnt++;
                else if(i%2 == 1 && j%2 == 1) cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
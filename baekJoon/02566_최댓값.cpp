#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[10][10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin >> arr[i][j];
        }
    }
    int mx = arr[0][0];
    int idx=0,idy=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if ( mx <= arr[i][j] ){
                mx = arr[i][j];
                idx=i;
                idy=j;
            }
        }
    }
    cout << mx << '\n';
    cout << idx << " " << idy << '\n';
    return 0;
}
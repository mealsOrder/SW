#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<pair<int,int>>v;
const int MAX = 9;
int arr[11][11];
int main() {
    
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin >>arr[i][j];
        }
    }

    int mx = arr[0][0];
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(arr[i][j]>mx){
                mx = arr[i][j];
            }
        }
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(arr[i][j] == mx){
                v.push_back({i,j});
            }
        }
    }

    sort(v.begin(),v.end());
    cout << mx << endl;
    cout << v[0].first << " " << v[0].second << endl;

    return 0;
}
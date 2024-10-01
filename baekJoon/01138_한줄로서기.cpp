#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
const int MX = 11;
int N;
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[j] == 0){
                cout << j+1 << " ";
                for(int k = j;k>=0;k--){
                    arr[k]--;
                }
                break;
            }
        }
    }


    return 0;
}
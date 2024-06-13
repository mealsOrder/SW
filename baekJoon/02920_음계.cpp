#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[9];
    for(int i=0;i<8;i++)cin >> arr[i];
    
    string res="";
    for(int i=0;i<7;i++){
        if (arr[i] < arr[i+1]){
            if(res =="descending"){
                res = "mixed";
                break;
            }
            res = "ascending";
        }
        else if(arr[i] > arr[i+1]){
            if(res == "ascending"){
                res = "mixed";
                break;
            }
            res="descending";
        }
    }
    cout << res << '\n';

    return  0;
}
        
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int MX = 6;
int arr[MX];
int main(){
    int sum=0;
    for(int i=0;i<5;i++){
        cin >> arr[i];
        sum += arr[i];    
    }
    sort(arr,arr+5);
    int avg = sum/5;
    int mid = arr[2];
    
    cout << avg << '\n';
    cout << mid << '\n';
	return 0;
}
        
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int MX = 1001;
int arr[MX];
int main(){
    int N,K;
    cin >> N>>K;
    for(int i=0;i<N;i++)cin >> arr[i];
    sort(arr,arr+N,greater<>());
    cout << arr[K-1]<<"\n";
	return 0;
}
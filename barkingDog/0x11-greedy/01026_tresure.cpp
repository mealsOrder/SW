#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 51;
int arr[MX];
int brr[MX];
bool com(int a, int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)cin >> arr[i];
    for(int i=0;i<N;i++)cin >> brr[i];

    sort(arr,arr+N);
    sort(brr,brr+N,com);
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += arr[i]*brr[i];
    }
    cout << sum;



    return  0;
}
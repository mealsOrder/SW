#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 100001;
int arr[MX];
bool cmp(int a, int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+N+1,cmp);
    int mx_v = 0;
    for(int i=1;i<=N;i++){
        mx_v = max(mx_v,i+arr[i]);
    }
    cout << mx_v+1;
    return 0;
}
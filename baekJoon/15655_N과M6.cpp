#include<iostream>
#include<algorithm>

using namespace std;
const int MX = 10;
int N,M;
int ans[MX];
int arr[MX];
void back(int x,int idx){
    if(x==M){
        for(int i=0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=idx;i<N;i++){
            ans[x] = arr[i];
            back(x+1,i+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++)cin>>arr[i];

    sort(arr,arr+N);
    back(0,0);
    return 0;
}
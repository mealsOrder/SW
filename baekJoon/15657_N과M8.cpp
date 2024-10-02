#include<iostream>
#include<algorithm>

using namespace std;
const int MX = 31;
int N,M;
int arr[MX];
int ans[MX];
bool vis[MX];
void back(int num,int x){
    if(x == M){
        for(int i=0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=num;i<N;i++){
            ans[x] = arr[i];
            back(i,x+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    back(0,0);
    return 0;
}
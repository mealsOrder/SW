#include<iostream>
#include<algorithm>

using namespace std;
const int MX = 31;
int N,M;
int arr[MX];
int ans[MX];
bool vis[MX];
void back(int x){
    if(x == M){
        for(int i=0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=0;i<N;i++){
            if(!vis[i]){
                ans[x] = arr[i];
                vis[i] = true;
                back(x+1);
                vis[i] = false;
            }
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
    back(0);
    return 0;
}
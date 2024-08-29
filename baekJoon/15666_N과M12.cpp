#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int MX = 30;
int arr[MX];
int ans[MX];
bool vis[MX];
int N,M;
int pre;
void back(int x){
    if(x==M+1){
        for(int i=1;i<=M;i++){ // 말씀해 주신대로 수정한 부분
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        int last = 0;
        for(int i=1;i<=N;i++){
            pre = ans[x-1]; // 이제 맞겠지?
            if(pre <= arr[i] && last != arr[i] ){
                last = ans[x] = arr[i];
                back(x+1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+N+1); // 말씀해 주신대로 수정한 부분
    back(1);             // 말씀해 주신대로 수정한 부분
    return 0;
}
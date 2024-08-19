#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int MX = 31;
int N,M;
int arr[MX];
int ans[MX];
bool vis[MX];
void back(int x){
    if(x == M){
        for(int i=0;i<M;i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    else{
        int last = 0; // 수열의 마지막 값
        for(int i=0;i<N;i++){
            // 마지막 값과 새로 추가되는 값이 같을때, 중복되는 수열이 만들어지므로
            if(!vis[i] && arr[i]!=last){ // 중복되는 수열을 배제 시킴
                last = ans[x] = arr[i];
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
    for(int i=0;i<N;i++)
        cin >> arr[i];

    sort(arr,arr+N);
    back(0);
    return 0;
}
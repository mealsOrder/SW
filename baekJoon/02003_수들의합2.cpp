#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 10001;
int N,M;
int arr[MX];
int ans;
void chk(int x){
    if(x == M) ans ++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=i;j<=N;j++){
            
            if(sum < M){
                sum += arr[j];
                if(sum == M){
                    ans ++;
                    //cout << ans << '\n';
                    break;
                }
            }
            else if(sum == M){
                ans++;
                break;
            }
            else{
                break;
            }
           
        }
    }
    cout << ans <<'\n';
    return 0;
}
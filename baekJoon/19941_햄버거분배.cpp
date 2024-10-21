#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MX = 20001;
int N,K,ans;
bool vis[MX];
string str;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> K;
    
    cin >> str;

    for(int i=0;i<N;i++){
        if(str[i] == 'P'){
            for(int j = i-K;j<=i+K;j++){
                // 배열 범위 초과나 미만 조건
                if( j <0 || j >=N)continue; 
                if(!vis[j] && str[j] == 'H'){
                    vis[j]=true;
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

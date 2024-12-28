#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MX = 101;
vector<int>v;
int N;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=N-1;i>=0;i--){
        int mx = v[i];

        if( i == 0) break;

        while(1){

            if(mx <= v[i-1]){

                ans++;
                v[i-1]--;
            }
            else{
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
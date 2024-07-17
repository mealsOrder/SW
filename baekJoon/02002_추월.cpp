#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MX = 1005;
map<string,int>inC;
int outC[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    int ans = 0;
    for(int i=0;i<N;i++){
        string num;
        cin >> num;
        inC[num] = i; // 들어온 순서  
    }
    for(int i=0;i<N;i++){
        string num;
        cin >> num;                
        outC[i] = inC[num]; // outC[나간순서] = 들어온 순서
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if( outC[i] > outC[j] ){
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
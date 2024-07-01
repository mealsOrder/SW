#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1001;

int ans[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<int>q;
    int N;
    cin >> N;
    
    for(int i=N;i>=1;i--){
        q.push(i);
        for(int j=0;j<i;j++){
            int cur = q.front();
            q.pop();
            q.push(cur);
        }
    }
    int c=1;
    while(!q.empty()){
        int cur = q.front();
        ans[c] = cur;
        q.pop();
        c++;
    }
    for(int i=N;i>=1;i--)cout << ans[i] << " ";
    return 0;
}
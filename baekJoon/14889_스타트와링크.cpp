#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 21;
int s[MX][MX];
int N;
bool vis[MX];
int ans = 1e9;

void func(int idx, int cnt){
    if(cnt == N/2){
        vector<int>start,link;

        for(int i=0;i<N;i++){
            if(vis[i])start.push_back(i);
            else link.push_back(i);
        }

        int st_sum = 0, li_sum = 0;

        for(int i=0;i<N/2;i++){
            for(int j=i+1;j<N/2;j++){
                int s1 = start[i],s2 = start[j];
                int l1 = link[i],l2 = link[j];
                st_sum += s[s1][s2] + s[s2][s1];
                li_sum += s[l1][l2] + s[l2][l1];
            }
        }
        ans = min(ans,abs(st_sum-li_sum));
        return;
    }

    for(int i=idx;i<N;i++){
        vis[i] = true;
        func(i+1,cnt+1);
        vis[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> s[i][j];
        }
    }

    func(0,0);

    cout << ans << '\n';

    return 0;
}

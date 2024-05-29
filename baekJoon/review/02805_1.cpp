#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MX = 1000001;
long long tree[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    cin >> N>>M;
    for(long long i=0;i<N;i++) cin >> tree[i];
    sort(tree,tree+N);
    long long ans = 0;
    long long lef = 0;
    long long rig = tree[N-1];
    while(lef <= rig){
        long long sum = 0;
        long long mid = (lef+rig)/2;

        for(long long i=0;i<N;i++){
            if(tree[i]>mid) sum += tree[i]-mid;
        }

        if(sum >= M){
            lef = mid+1;
            ans = max(ans,mid);
        }
        else{
            rig = mid -1;
        }
        
    }
    cout << ans;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int N,C;
int ans;

bool check(vector<int>&v,int mid,int c){
    int cnt = 1;
    int pre = v[0];
    for(int i=0;i<v.size();i++){
        if(v[i] - pre >= mid){
            cnt++;
            pre = v[i];
        }
    }
    return cnt>=c;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N>>C;
    vector<int>a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    int lef = 1;
    int rig = a[N-1] - a[0];

    while(lef<=rig){
        int mid = (lef+rig)/2;
        if(check(a,mid,C)){
            if(ans < mid) {
                ans = mid;
            }
            lef = mid+1;
        }
        else{
            rig = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
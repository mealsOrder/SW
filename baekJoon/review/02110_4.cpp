#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,C;
int ans = 0;

bool check(vector<int>&v,int mid,int c){
    int cnt = 1;
    int pre = v[0];
    for(int i=1;i<v.size();i++){
        if(v[i] - pre >= mid){
            cnt++;
            pre = v[i];
        }
    }
    return cnt>=c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N>>C;
    vector<int>h(N);
    for(int i=0;i<N;i++) cin >> h[i];

    sort(h.begin(),h.end());

    int lef = 1; 
    int rig = h[N-1]-h[0]; 
    int mid;
    while(lef<=rig){
        mid = (lef+rig)/2;
        if(check(h,mid,C)){
            if(ans<mid){
                ans = mid;
            }
            lef = mid+1;
        }
        else{
            rig = mid-1;
        }
    }
    cout << ans << '\n';
	return 0;
}
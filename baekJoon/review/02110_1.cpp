#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,C;
int ans = 0;
bool check(vector<int>&v,int mid,int c){
    int cnt=1;
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
    cin >> N>>C;
    vector<int>house(N);
    for(int i=0;i<N;i++)cin >> house[i];
    sort(house.begin(),house.end());
    int lef = 1; // 최소 거리
    int rig = house[N-1]- house[0]; // 최대 거리

    while(lef<=rig){
        int mid = (lef+rig)/2;
        if(check(house,mid,C)){
            if(ans<mid){
                ans = mid;
            }
            lef = mid+1;
        }
        else{
            rig = mid-1;
        }
    }
    cout << ans;
    return 0;
}
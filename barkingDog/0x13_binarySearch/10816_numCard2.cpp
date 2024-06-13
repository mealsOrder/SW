#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N;
    vector<int>v(N);
    for(int i=0;i<N;i++)cin >> v[i];
    sort(v.begin(),v.end());
    
    cin >> M;
    for(int i=0;i<M;i++){
        int target;
        cin >> target;

        int res = upper_bound(v.begin(),v.end(),target) - lower_bound(v.begin(),v.end(),target);
        cout << res << " ";
    }


    return  0;
}
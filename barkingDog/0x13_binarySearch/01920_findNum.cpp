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
    for(int i=0;i<N;i++) cin >> v[i];
    cin >> M;
    vector<int>target(M);
    for(int i=0;i<M;i++) cin>>target[i];

    sort(v.begin(),v.end());

    for(int num : target){
        int lef = 0;
        int rig = N-1;
        bool flag = false;
        while(lef<=rig){
            int mid = (lef+rig)/2;
            if(v[mid] == num){
                flag = true;
                break;
            }else if(v[mid] > num){
                rig = mid - 1;
            }else{
                lef = mid + 1;
            }
        }
        if(flag) cout << "1\n";
        else cout << 0 << '\n';
        
    }

    return  0;
}
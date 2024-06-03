#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 500001;
string arr[MX]; // 듣
string brr[MX]; // 보
vector<string>ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >>N>>M;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<M;i++){
        cin >> brr[i];
    }
    sort(arr,arr+N);
    sort(brr,brr+N);
    
    int mid = 0;
    int cnt = 0;
    for(int i=0;i<M;i++){
        int lef = 0;
        int rig = N-1;
        string target = brr[i];
        while(lef<=rig){
            mid = (lef+rig)/2;
            if(arr[mid] == target){ // 같은경우
                cnt++;
                ans.push_back(target);
                break;
            }
            else if(arr[mid] < target) lef = mid+1;
            else rig = mid-1;
        }
    }
    cout << cnt << '\n';
    for(string k:ans) cout << k << '\n';
    return  0;
}
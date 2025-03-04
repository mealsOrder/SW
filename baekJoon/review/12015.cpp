#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;

    vector<int>arr(N);
    vector<int>lis;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int x: arr){
        // x가 들어갈 위치 찾기
        int pos = lower_bound(lis.begin(),lis.end(),x) - lis.begin();
        
        if(pos == lis.size()){
            lis.push_back(x);
        }
        else{
            lis[pos] = x;
        }
    }
    cout << lis.size();
    return 0;
}
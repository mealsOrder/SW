#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int>arr(N);

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<int>lis;

    for(int x:arr){
        int pos = lower_bound(lis.begin(),lis.end(),x) - lis.begin();
        if(pos == lis.size()){
            lis.push_back(x);
        }
        else{
            lis[pos] = x;
        }
    }

    cout << lis.size() << '\n';
    return 0;
}
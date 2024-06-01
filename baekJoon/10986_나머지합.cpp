#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 1000001;
long long arr[MX];
vector<pair<int,int>>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >>N>>M;
    for(int i=1;i<=N;i++) cin >> arr[i];
    long long sum=0;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            v.push_back({i,j});
        }
    }
    int cnt=0;
    for(int i=0;i<v.size();i++){
        sum=0;
        for(int x=v[i].first;x <= v[i].second;x++){
            sum+= arr[x];    
        }
        if(sum!=0 && sum%M == 0){
            cnt++;
        }
    }    
    cout << cnt;    
    return 0;
}
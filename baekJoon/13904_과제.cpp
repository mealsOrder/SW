#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 1001;
int N;
int day[MX];
vector<pair<int,int>>v;
bool cmp(pair<int,int>a, pair<int,int>b){
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int d,w;
        cin >> d >> w;
        v.push_back({w,d}); // v{점수,마감일}
    }
    sort(v.begin(),v.end(),greater<>());//greater<>() 써도 되는데 직접 구현해봄

    for(int i=0;i<N;i++){
        for(int j = v[i].second;j>=1;j--){
            if(!day[j]){
                day[j] = v[i].first;
                break;
            } 
        }
    }
    int ans = 0;
    for(int i=1;i<=MX;i++)ans+=day[i];
    cout << ans;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int,int>>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int s,e;
        cin >> s>>e;
        v.push_back({e,s});
        // first = 끝나는시간
        // second = 시작 시간
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    int endTime=0;
    for(int i=0;i<N;i++){
        if(v[i].second < endTime)continue;
        cnt ++;
        endTime = v[i].first;
    }
    cout << cnt;
    return  0;
}
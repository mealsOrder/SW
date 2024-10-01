#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
const int MX = 100001;
int N;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b>> c;
        v.push_back({b,c});
    }

    sort(v.begin(),v.end());

    int en = v[0].second;

    pq.push(en);
    for(int i=1;i<N;i++){
        if(pq.top() <= v[i].first){
            pq.pop();
        }        
        pq.push(v[i].second);
    }
    cout << pq.size();
    return 0;
}
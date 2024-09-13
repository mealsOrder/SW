#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq;
vector<pair<int,int>>v;
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;

        v.push_back({a,b}); 
    }
    sort(v.begin(),v.end());

    pq.push(v[0].second);
    
    for(int i=1;i<N;i++){
        
        if(pq.top() <= v[i].first ){
            pq.pop();
        }
        pq.push({v[i].second});
    }
    cout << pq.size();
    return 0;
}
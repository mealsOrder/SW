#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >>N;

    vector<int>v(N*N);
    priority_queue<int,vector<int>,greater<>>pq;
    priority_queue<int,vector<int>,greater<int>>rq;
    int cnt=0;
    for(int i=0;i<N*N;i++){
        cin >> v[i];

        pq.push(v[i]);

        if(N<(int)pq.size()){
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
    return  0;
}
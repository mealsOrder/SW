#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,K;
    cin >> N >> K;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        pq.push(a);
        if(pq.size() > N-K+1) pq.pop();
    }

    cout << pq.top();

    return 0;
}
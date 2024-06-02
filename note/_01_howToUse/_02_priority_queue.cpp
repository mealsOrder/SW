#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue< pair<int,int> >pq;
    pq.push({1,2});
    pq.push({1,3});
    pq.push({3,1});
    pq.push({2,5});
    pq.push({3,1});

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}
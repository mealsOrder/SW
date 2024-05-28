#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;

int main() {
    queue<int>q;
    int N,K;
    int cnt = 1;
    cin >>N>>K;

    for(int i=1;i<=N;i++) q.push(i);
    cout << "<";
    while(!q.empty()){
        int cur = q.front();
        if(cnt%K == 0){
            q.pop();
            if(q.empty()) cout << cur << ">";
            else cout << cur <<", ";
        }
        else{
            q.pop();
            q.push(cur);
        }
        cnt++;
    }
    
    return 0;
}
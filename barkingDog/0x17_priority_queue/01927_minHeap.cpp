#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int>v(N);
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i=0;i<N;i++){
        
        cin >> v[i];
        if(v[i] == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << "0" << "\n";
            }
        }
        else{
            pq.push(v[i]);
        }
    }

    return  0;
}
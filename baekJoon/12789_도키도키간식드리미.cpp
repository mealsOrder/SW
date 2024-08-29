#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MX = 1001;
queue<int>q;
stack<int>s;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        q.push(a);
    }
    int k = 1;
    while(!q.empty()){
        int cur = q.front();
        if(cur == k){
            q.pop();
            k++;
        }
        else{
            if(!s.empty() && k == s.top()){
                s.pop();
                k++;
            }
            else{
                s.push(cur);
                q.pop();
            }
        }
    }
    while(!s.empty()){
        if(k!=s.top()) break;
        else{
            s.pop();
            k++;
        }
    }
    cout << ((s.empty()) ? "Nice" : "Sad") << '\n';
	return 0;
}

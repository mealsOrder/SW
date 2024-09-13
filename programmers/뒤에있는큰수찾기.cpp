#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> solution(vector<int> num){
    vector<int>ans;
    stack<int>s;
    
    for(int i=0;i<num.size();i++){
        while(!s.empty() && num[i] > num[s.top()]){
            ans[s.top()] = num[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int>v = {2,3,3,5};
    solution(v);
    return 0;
}
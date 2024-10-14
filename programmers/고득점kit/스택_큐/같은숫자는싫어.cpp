#include <vector>
#include <iostream>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    stack<int>s;
    s.push({arr[0]});
    for(int i=1;i<arr.size();i++){
        if(s.top() == arr[i])continue;
        else{
            s.push({arr[i]});
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
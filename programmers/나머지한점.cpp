#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans(2,0);
    
    for(int i=0;i<v.size();i++){
        
        ans[0] ^= v[i][0];
        ans[1] ^= v[i][1];
    }
    return ans;
}

int main(){

    return 0;
}
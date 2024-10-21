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
    int x1,x2,x3,y1,y2,y3;
    cin >> x1>>y1>>x2>>y2>>x3>>y3;
    cout << int(x1^x2^x3) << " " << int(y1^y2^y3) << '\n';
    return 0;
}
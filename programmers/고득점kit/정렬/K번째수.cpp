#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
    vector<int> ans;
    
    for(int i=0;i<commands.size();i++){
        vector<int>tmp;
        int st = commands[i][0];
        int en = commands[i][1];
        int cn = commands[i][2];
        
        for(int j=st-1;j<en;j++){
            tmp.push_back(arr[j]);
        }
        sort(tmp.begin(),tmp.end());
        
        ans.push_back(tmp[cn-1]);
    }
    
    return ans;
}

int main(){
    vector<int>a = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>>v = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    solution(a,v);
}
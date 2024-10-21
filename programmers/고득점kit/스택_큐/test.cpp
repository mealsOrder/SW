#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> ans;
    
    deque<int>s;
    for(int i=0;i<p.size();i++) s.push_back(p[i]);
    
    for(int i=0;i<p.size();i++){
        int init = p[i];
        int cnt = 0;
        deque<int>k = s;
        for(int j = 0 ;j<i+1;j++) k.pop_front();
        while(!k.empty() && k.back() >= init){
            k.pop_back();
            cnt++;
        }
        while(!k.empty()){
            k.pop_back();
            //cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> c) {
    int ans = 0;

    sort(c.begin(),c.end(),greater<int>());

    if(!c[0]) return 0;

    for(int i=0;i<c.size();i++){
        if(c[i] > i){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}

int main(){
    vector<int>v = {3,0,6,1,5};
    cout << solution(v);

    return 0;
}
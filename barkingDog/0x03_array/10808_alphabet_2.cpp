#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int ans[26];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;    
    cin >> s;
    for(auto c:s)
        ans[c-'a']++;
    
    for(int i=0;i<26;i++)cout<<ans[i]<<" ";
	return 0;
}

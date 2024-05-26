#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
string A = "abcdefghijklmnopqrstuvwxyz";
int ans[26];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;    
    cin >> s;

    for(int j=0;j<26;j++){
        for(int i=0;i<s.size();i++){
            if(s[i] == A[j] ){
                ans[j]++;
            }
        }
    }
    for(int i=0;i<26;i++)cout<<ans[i]<<" ";
	return 0;
}

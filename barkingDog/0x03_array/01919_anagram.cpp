#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 26;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    int s[26]={};
    int ans = 0;
    for(auto k :a) s[k-'a']++;
    for(auto k :b) s[k-'a']--;

    for(int i:s){
        ans += abs(i);
    }
    cout << ans;
    return 0;
}
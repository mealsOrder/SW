#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 100001;
int dp[MX];
int dp2[MX];
int solution(vector<int> sticker)
{
    int ans=0;
    int N = sticker.size();

    if(N==1) return sticker[0];
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for(int i=2; i<N-1; i++){
        dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
        
    }
    dp2[0] = 0;
    dp2[1] = sticker[1];
    sticker.push_back(sticker[0]);
    for(int i=2; i<N; i++){
        dp2[i] = max(dp2[i-1],dp2[i-2]+sticker[i]);
        
    }
    ans = max(dp[N-2],dp2[N-1]);
    return ans;
}
int main(){
    vector<int>s1;
    //string op1[6] = {"L", "P Z", "L", "D","R","l x"};
    s1.push_back(14);
    s1.push_back(6);
    s1.push_back(5);
    s1.push_back(11);
    s1.push_back(3);
    s1.push_back(9);
    s1.push_back(2);
    s1.push_back(10);
    
    cout << solution(s1) << '\n';

    vector<int>s2;
    //string op2[5] = {"P a", "P b", "L","l c","l d"};
    s2.push_back(1);
    s2.push_back(3);
    s2.push_back(2);
    s2.push_back(5);
    s2.push_back(4);

    //cout << solution(s2) << '\n';
	return 0;
}
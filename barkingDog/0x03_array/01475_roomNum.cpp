#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int s[10];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A;
    cin >> A;
    int cnt=0;
    while(A>0){
        s[A%10]++;
        A/=10;
    }
    
    for(int i=0;i<10;i++){
        if(i==6||i==9)continue;
        cnt=max(cnt,s[i]);
    }
    
    cnt = max(cnt,(s[6]+s[9]+1)/2);
    cout << cnt;

	return 0;
}
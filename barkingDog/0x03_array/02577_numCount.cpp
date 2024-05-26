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
    
    int A,B,C;
    cin >>A>>B>>C;
    int sum = A*B*C;

    while(sum>0){
        s[sum%10]++;
        sum/=10;
    }

    for(int i=0;i<10;i++){
        cout << s[i] << '\n';
    }

	return 0;
}
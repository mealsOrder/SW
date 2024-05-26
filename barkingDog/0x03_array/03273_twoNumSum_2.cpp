#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAX = 2000001;
int s[MAX];
/**
 * 공간복잡도 O(2000000), 시간복잡도 O(n)
*/
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >>N;

    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        s[t]++;
    }
    int X;
    cin >>X;
    int cnt = 0;
    for(int i=0;i< (X+1)/2;i++){
        if(s[i]==1 && s[X-i]==1 ) cnt++;
    }
    cout << cnt;
	return 0;
}


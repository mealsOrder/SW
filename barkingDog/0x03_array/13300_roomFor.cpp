#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAX = 1001;
int s[MAX][MAX];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N>>K;
    int room=0;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        s[b][a]++;
        
    }
    for(int j=1;j<=6;j++){
        room += (s[j][0]+(K-1))/K;
        room += (s[j][1]+(K-1))/K;
    }

    cout << room;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAX = 101;
int s[MAX];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    int M,cnt =0;
    cin >> M;

    for(int i=0;i<N;i++){
        if(s[i] == M)cnt++;
    }
    cout << cnt;
	return 0;
}
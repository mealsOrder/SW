#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int MAX = 201;
int a[MAX];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

    int N,v;
    cin >> N;
    while(N--){
        int t;
        cin >> t;
        a[t+100]++;
    }
    cin >> v;
    cout << a[100+v];
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>v;
int main(){
	
    int N,M;

    cin >>N>>M;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
	sort(v.begin(),v.end());
    for(int i=0;i<M;i++){

        int b;
        cin >> b;

        int res = upper_bound(v.begin(),v.end(),b) - lower_bound(v.begin(),v.end(),b);
        cout << res << '\n';
    }

	return 0;
}
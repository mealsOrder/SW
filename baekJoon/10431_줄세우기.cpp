#include <iostream>
#include <vector>
#include<algorithm>
#include<stack>
using namespace std;
// solve time : 20 min
const int N = 20;
int arr[21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    int T;
    cin >> T;
                                               
    for(int t=1;t<=T;t++){
        fill(arr+1,arr+20+1,0);
        stack<int>s;
        int cnt = 0;
        int a;
        cin >> a;
        for(int u=1;u<=N;u++){
            cin >> arr[u];
        }
        
        for(int i=1;i<=N;i++){
            int k = arr[i];
            for(int j=i+1;j<=N;j++){
                if(k > arr[j])cnt++;
            }
        }
        cout << t << " " <<  cnt << '\n';

    }

	return 0;
}
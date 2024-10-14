#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
// solve time : 10 min
const int MX = 100001;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    char op;
    cin >> op;
    int ans = 0;
    set<string>s;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    int a = s.size();
    if( op  == 'Y') {
        ans = a;
    }
    else if(op == 'F') ans = a/2;
    else if(op == 'O') ans = a/3;
    cout << ans << '\n';
	return 0;
}
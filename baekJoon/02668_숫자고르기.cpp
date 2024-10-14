#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MX = 101;

int N;
int input[MX];
bool vis[MX];
set<int> ans;
bool isRight;
void dfs(int firstNum,int num) {	
	if (vis[num]) {
		if (firstNum == num) {
				isRight = true;
				ans.insert(num);
		}
		return;
	}
	vis[num] = true;
	dfs(firstNum,input[num]);
	if (isRight) {
		ans.insert(num);
		ans.insert(input[num]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= N; i++) {
		vis[i] = true;
		dfs(i,input[i]);
		memset(vis, false, MX);
		isRight = false;
	}
	cout << ans.size() << '\n';
	for (auto o : ans) {
		cout << o << '\n';
	}
	return 0;
}
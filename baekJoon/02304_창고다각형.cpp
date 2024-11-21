#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	stack<pair<int,int>>s;
	s.push({ v[0].first,v[0].second });
	for (int i = 1; i < n; i++) {
		if (v[i].second > s.top().second) s.push({ v[i].first, v[i].second });
	}
	int x = s.top().first;
	int y = s.top().second;
	while (s.size()>=2) {
		int width = s.top().first;
		s.pop();
		width -= s.top().first;
		int height = s.top().second;
		ans += width * height;
	}
	s.pop();
	//
	s.push({ v[n - 1].first,v[n - 1].second });
	for (int i = n - 2; i >= 0; i--) {
		if (v[i].second > s.top().second) s.push({ v[i].first,v[i].second });
	}
	if (x == s.top().first) ans += s.top().second;
	else ans += (s.top().first - x + 1) * s.top().second;
	while (s.size() >= 2) {
		int width = s.top().first;
		s.pop();
		width -= s.top().first;
		width *= -1;
		int height = s.top().second;
		ans += width * height;
	}
	s.pop();
	cout << ans;
}
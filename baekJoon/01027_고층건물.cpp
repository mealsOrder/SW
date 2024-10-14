#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
	int N;
	cin >> N;
	vector<int>arr(N + 1);
	vector<int>cnt(N + 1, 0);
	for (int i = 1; i <= N; i++)cin >> arr[i];
	
    for (int now = 1; now <= N; now++) {
		double maxx = -9999999999;
		for (int i = now + 1; i <= N; i++) {
			double level = (double)(arr[i] - arr[now]) / (i - now);//기울기
			if (level > maxx) {
				cnt[now]++;
				cnt[i]++;
				maxx = level;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; i++)res = max(res, cnt[i]);
	cout << res;
	return 0;
}
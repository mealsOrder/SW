#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	int n;
	cin >> n;

	string st[4];
	int num[4];
	int a = 5;
	string cnt;
	for (int i = 0; i < n; i++) {
		cin >> st[i] >> num[i];
		if (a > num[i]) {
			a = num[i];	
            cnt = st[i];
		}
	}

	cout << cnt << '\n';

    return 0;
}
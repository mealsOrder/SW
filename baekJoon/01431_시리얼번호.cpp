#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;

bool compare(string a, string b)
{
	// 길이가 같지 않을 시
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
	{  //같을때는 숫자만 더해준다.
		int asum = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
			{
				asum += a[i] - '0';
			}
		}
		int bsum = 0;
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0)
			{
				bsum += b[i] - '0';
			}
		}
		// 숫자의 합이 다르면 합이 작은 순서대로
		if (asum != bsum) {
			return asum < bsum;
		}
		// 합이 같다면 알파벳 순으로
		else {
			return a < b;
		}
	}
}
int main()
{
	vector<string> v;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	return 0;
}
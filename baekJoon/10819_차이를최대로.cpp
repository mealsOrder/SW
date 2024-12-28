#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	vector<int> arr;
	int N;
	int element;
	int sum;
	int result = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> element;
		arr.push_back(element);
	}

	sort(arr.begin(), arr.end());

	while (next_permutation(arr.begin(), arr.end())) {
		sum = 0;
		for (int i = 0; i < arr.size() - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		result = max(result, sum);
	}

	cout << result;

	return 0;
}
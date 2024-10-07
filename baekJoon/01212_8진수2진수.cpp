#include <iostream>
#include <string>

using namespace std;
int main(){

	string a;
	string arr[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	int idx;

	cin >> a;

	for (int i = 0; i < a.length(); i++) {

		idx = a[i] - '0';
		if (i == 0) cout << stoi(arr[idx]);
		else cout << arr[idx];
	}
}
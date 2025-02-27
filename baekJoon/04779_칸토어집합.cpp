#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;

void cantor(int n) {
	int size = pow(3, n - 1);

	// N = 0 인 경우 "-" 출력
	if (n == 0) {
		cout << "-";
		return;
	}

	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
	cantor(n - 1);
	for (int i = 0; i < size; i++) {
		cout << " ";
	}
	cantor(n - 1);

}

int main() {
    ios_base::sync_with_stdio(0);  
    cin.tie(0);cout.tie(0);  

	int N;

	while (cin >> N) {
		cantor(N);
		cout << "\n";
	}

	return 0;
}
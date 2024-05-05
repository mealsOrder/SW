#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#define INFI 2147483648
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}


int main() {
    fastIO();
    int N;
    cin >> N;
    vector<int> mx(3);
    vector<int> mn(3);
    vector<int> temp(3);
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        temp[0] = max(mx[0] + A, mx[1] + A);
        temp[1] = max({mx[0] + B, mx[1] + B, mx[2] + B });
        temp[2] = max(mx[1] + C, mx[2] +C);
        
        for (int j = 0; j < 3; j++) mx[j] = temp[j];

        temp[0] = min(mn[0] + A, mn[1] + A);
        temp[1] = min({ mn[0] + B, mn[1] + B, mn[2] + B });
        temp[2] = min(mn[1] + C, mn[2] + C);
        
        for (int j = 0; j < 3; j++) mn[j] = temp[j];

    }
    cout << max({ mx[0],mx[1],mx[2] }) << " " << min({mn[0],mn[1],mn[2]});
}

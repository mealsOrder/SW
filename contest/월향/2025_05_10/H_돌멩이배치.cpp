#include <iostream>
#include <vector>
using namespace std;

int ceil_div(int a, int b){
    return (a + b - 1) / b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int N, K, L, R;
        cin >> N >> K >> L >> R;

        int min_stones = ceil_div(N * L, K);
        int max_stones = (N * R) / K;

        if(min_stones > max_stones){
            cout << -1 << '\n';
            continue;
        }

        int stones = min_stones;
        vector<int> res(N, 0);

        for(int i = 0; i < stones; ++i)
            res[i % N] = 1;

        for(int i = 0; i < N; ++i)
            cout << res[i] << " ";
        cout << '\n';
    }

    return 0;
}

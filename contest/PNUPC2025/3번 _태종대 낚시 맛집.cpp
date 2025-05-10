#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
const int MX = 101;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> x(n); // 먹성
    vector<int> s(n); // 크기
    vector<int> w(n); // 가격

    for(int i = 0; i < n; i++){
        cin >> x[i] >> s[i] >> w[i];
    }

    int ans = 0;

    for(int C = 1; C <= 10000; C++){
        int t = C;
        int profit = 0;
        vector<bool> v(n, false);

        while(true){
            int idx = -1;
            int max_size = -1;

            for(int i = 0; i < n; i++){
                if(!v[i] && x[i] <= t){
                    if(s[i] > max_size){
                        max_size = s[i];
                        idx = i;
                    }
                }
            }

            if(idx == -1) break;

            t -= x[idx];
            profit += w[idx];
            v[idx] = true;
        }

        int total = profit - C * c;
        if(total > ans) ans = total;
    }

    cout << ans << '\n';
    return 0;
}

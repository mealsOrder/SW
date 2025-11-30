#include<iostream>
using namespace std;

int func(int m){
    int a = 0, b = 1, c, res = 0;

    while (true){
        c = (a + b) % m;
        a = b;
        b = c;
        res++;

        if (a == 0 && b == 1) break;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--){
        int i, m;
        cin >> i >> m;
        cout << i << ' ' << func(m) << '\n';
    }

    return 0;
}

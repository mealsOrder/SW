#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 200005;

vector<ll> fact(MAX), inv_fact(MAX);

// 거듭제곱: base^exp % MOD
ll power(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

// nCk = fact[n] * inv_fact[k] * inv_fact[n-k]
ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();

    int T;
    cin >> T;
    while (T--) {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        if (A + B + C != N || A != C + 1) {
            cout << 0 << '\n';
        } else {
            cout << comb(A + B - 1, B) << '\n'; // A + B - 1 = C + 1 + B - 1 = B + C
        }
    }

    return 0;
}

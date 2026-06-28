#include <iostream>
using namespace std;

using int64 = long long;
const int MOD = 2026;

// 快速幂：计算 a^b % MOD
int64 qpow(int64 a, int64 b) {
    int64 res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 返回 sum_{i=0}^{n-1} t^i % MOD
int64 geometric_sum(int64 t, int64 n) {
    if (n == 0) return 0;
    if (n == 1) return 1 % MOD;

    if (n % 2 == 0) {
        // S(n) = S(n/2) * (1 + t^(n/2))
        int64 half = geometric_sum(t, n / 2);
        int64 p = qpow(t, n / 2);
        return half * (1 + p) % MOD;
    } else {
        // S(n) = S(n-1) + t^(n-1)
        return (geometric_sum(t, n - 1) + qpow(t, n - 1)) % MOD;
    }
}

int main() {
    int64 a, T, n;
    cin >> a >> T >> n;

    int64 sum = geometric_sum(T, n);
    int64 ans = a % MOD * sum % MOD;

    cout << ans % MOD << '\n';
    return 0;
}
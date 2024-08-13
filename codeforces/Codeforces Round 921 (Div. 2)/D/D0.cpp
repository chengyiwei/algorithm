#include <iostream>
#include <vector>
#include <string>

const int64_t MOD = 1000000007LL;

using namespace std;

bool __hack = ios::sync_with_stdio(false);
auto __hack1 = cin.tie(nullptr);

template<typename T>
T next() {
    T x;
    cin >> x;
    return x;
}

int64_t mod_pow(int64_t a, int64_t b) {
    int64_t r = 1;
    while (b) {
        if (b & 1) {
            r = r * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int64_t mod_inv(int64_t a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    freopen("D.in", "r", stdin);
    freopen("D0.out", "w", stdout);
    vector<int64_t> fact(200001);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    vector<int64_t> inv_fact(200001);
    inv_fact[fact.size() - 1] = mod_inv(fact[fact.size() - 1]);
    for (int i = fact.size() - 2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    auto binomial = [&](int n, int k) {
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    };
    int tests = next<int>();
    for (int test = 0; test < tests; ++test) {
        int64_t n = next<int>();
        int64_t m = next<int>();
        int64_t k = next<int>();
        int64_t ans = 0;
        int64_t p = mod_inv(n * (n - 1) / 2 % MOD);
        int64_t q = (1 + MOD - p) % MOD;
        int64_t coeff = k * p % MOD;
        int64_t add = 0;
        for (int64_t i = 1; i <= k; ++i) {
            int64_t s = i * (i - 1) / 2 % MOD;
            add = (add + s * binomial(k, i) % MOD * mod_pow(p, i) % MOD * mod_pow(q, k - i) % MOD) % MOD;
        }
        for (int i = 0; i < m; ++i) {
            int a = next<int>();
            int b = next<int>();
            int64_t f = next<int64_t>();
            if (f) {
                ans = (ans + coeff * f + add) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

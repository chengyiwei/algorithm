#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;
static const int MAXN = 100000 + 5;

long long qpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long fac[MAXN], ifac[MAXN];

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void init(int n = 100000) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = qpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> cnt(29, 0); // cnt[p] = 第 p 位出现次数

    // 从大到小恢复 cnt[p]
    for (int k = n; k >= 1; k--) {
        long long rem = b[k];

        // 减去所有 cnt[p] > k 的已知贡献
        for (int p = 0; p < 29; p++) {
            if (cnt[p] > k) {
                rem = (rem - (1LL << p) % MOD * C(cnt[p], k)) % MOD;
            }
        }

        rem %= MOD;
        if (rem < 0) rem += MOD;

        // rem = sum of 2^p where cnt[p] == k
        for (int p = 0; p < 29; p++) {
            if ((rem >> p) & 1LL) {
                cnt[p] = k;
            }
        }
    }
    for (int p = 0; p < 29; p++) {
        cout << "cnt[" << p << "] = " << cnt[p] << "\n";
    }


    // 构造任意一个满足每位出现次数的数组
    vector<int> a(n, 0);
    for (int p = 0; p < 29; p++) {
        for (int i = 0; i < cnt[p]; i++) {
            a[i] |= (1 << p);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
/*
1
5
22 24 10 1 0
*/
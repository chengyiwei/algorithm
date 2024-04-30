#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
    int T; cin >> T;
    while (T--) {
        LL a, b, TT; cin >> a >> b >> TT;
        vector<LL> fac (TT, 1);
        for (int i = 1; i < TT; i++) fac[i] = fac[i - 1] * i % TT;

        auto qpow = [&] (LL a, LL n) {
            LL ret = 1;
            while (n) {
                if (n & 1) ret = ret * a % TT;
                a = a * a % TT;
                n >>= 1;
            }
            return ret;
        };

        auto C = [&] (LL n, LL m) {
            if (n < m) return 0ll;
            return fac[n] * qpow(fac[m], TT - 2) % TT * qpow(fac[n - m], TT - 2) % TT;
        };

        std::function<LL(LL, LL)> Lucas;
        Lucas = [&] (LL n, LL m) {
            if (m == 0) return 1ll;
            return C(n % TT, m % TT) * Lucas(n / TT, m / TT) % TT;
        };

        cout << Lucas(a + b, a) << endl;
    }
    return 0;
}
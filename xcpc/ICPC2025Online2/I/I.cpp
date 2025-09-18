#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int P = 998244353;

int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;
    Z (int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator - () const {
        return Z(norm(P - x));
    }
    Z inv() const {
        // assert(x != 0);
        if (x == 0) {
            return 1;
        }
        return power(*this, P - 2);
    }
    Z &operator *= (const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator += (const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator -= (const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator /= (const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator * (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator + (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator - (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator / (const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator >> (std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator << (std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

int main() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
    }

    vector<Z> fac(n + 1, 0); fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    vector<Z> invfac(n + 1, 1); invfac[n] = power(fac[n], P - 2);
    for (int i = n - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1);

    vector<int> f(n);
    for (int i = 1; i < n; i++) {
        cout << "? 1 " << n << " " << i << endl;
        cin >> f[i];
    }

    cout << "! " << endl;
    int K; cin >> K;

    n -= 1;
    vector<Z> pre(n + 1, 0), suf(n + 1, 0); pre[0] = suf[n] = 1;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (K - i);
    for (int i = n; i > 0; i--) suf[i - 1] = suf[i] * (K - i);

    Z res = 0;
    for (int i = 0; i <= n; i++) {
        res += f[i] * pre[i] * suf[i] * invfac[i] * invfac[n - i] * (n - i & 1 ? -1 : 1);
    }

    cout << res << endl;
    return 0;
}
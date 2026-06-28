#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int TT = 1e9 + 7;


int Fac[maxn], inv[maxn];

int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return ans;
}

void init() {
    Fac[0] = 1;
    for (int i = 1; i < maxn; i++) Fac[i] = Fac[i - 1] * i % TT;
    inv[maxn - 1] = qpow(Fac[maxn - 1], TT - 2);
    for (int i = maxn - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % TT;

}

int C(int n, int m) {
    if (n < m) return 0;
    return Fac[n] * inv[m] % TT * inv[n - m] % TT;
}

vector<int> factors(int n) {
    vector<int> res;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

vector<int> prime_factors_counts(int n) {
    vector<int> res;
    int t = n;
    for (int i = 2; i <= sqrt(n); i++) {
        int cnt = 0;
        while (t % i == 0) t /= i, cnt++;
        if (cnt) res.push_back(cnt);
    }
    if (t > 1) res.push_back(1);
    return res;
}


int calc0(vector<int> &v, int k) {
    // 求解 gcd 无限制 lcm 是 t 的因子的方案数
    int prod = 1;
    for (int u : v) prod = prod * (u + 1) % TT;
    return C(prod, k);
}


int calc1(vector<int> &v, int k, int mask) {
    int prod = 1;
    bitset<30> b(mask);
    for (int i = 0; i < v.size(); i++) {
        prod = prod * (v[i] + 1 - b[i]) % TT;
    }
    return C(prod, k);
}

int calc2(vector<int> &v, int k) {
    // 求解 gcd = 1 的情况下，方案数
    int res = 0;
    for(int i = 0; i < (1 << v.size()); i++) {
        res = ((res + calc1(v, k, i) * qpow(-1, bitset<30>(i).count() % 2)) % TT + TT) % TT;
    }
    return res;
}

int calc3(vector<int> v, int k, int mask) {
    // mask 表示违反的规则，那么只能取 0 ~ v_i-1
    bitset<30> b(mask);
    for (int i = 0; i < v.size(); i++) 
        v[i] -= b[i];
    return calc2(v, k);
}

int calc4(vector<int> v, int k) {
    int res = 0;
    for (int i = 0; i < (1 << v.size()); i++) {
        res = ((res + calc3(v, k, i) * qpow(-1, bitset<30>(i).count() % 2)) % TT + TT) % TT;
    }
    return res;
}

signed main() {
    freopen ("E.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    init();
    int x, k; cin >> x >> k;
    int ans = 0;
    for (int u : factors(x)) {
        int t = x - u;
        if (t == 0) continue;
        t /= u; // 转化成 gcd = 1, lcm = t 的问题
        auto v = prime_factors_counts(t);
        ans = (ans + calc4(v, k)) % TT;
    }
    cout << ans << '\n';
    return 0;
}
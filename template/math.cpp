#include <bits/stdc++.h>


using i64 = long long;
constexpr int P = 998244353;

// 取模 需要保证 -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

// 快速幂
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

// 有限域
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

std::vector<int> rev; // 蝴蝶操作的下标映射
std::vector<Z> roots{0, 1}; // 

void dft(std::vector<Z> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    for (int i = 0; i < n; i++) {
        if (rev[i] < i)
            std::swap(a[i], a[rev[i]]);
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Z e = power(Z(3), (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

void idft (std::vector<Z> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

// 多项式
struct Poly {
    std::vector<Z> a;
    Poly() {}
    Poly(const std::vector<Z> &a) : a(a) {}
    Poly(const std::initializer_list<Z> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }
    Z operator[](int idx) const {
        if (idx < size()) {
            return a[idx];
        } else {
            return 0;
        }
    }
    Z &operator[](int idx) {
        return a[idx];
    }
    Poly modxk(int k) const { // 对x^k取模，保留前k项
        k = std::min(k, size());
        return Poly(std::vector<Z>(a.begin(), a.begin() + k));
    }
    Poly mulxk(int k) const { // x^k乘多项式，前面补k个0
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly divxk(int k) const { // 对x^k整除，去掉前k项
        k = std::min(k, size());
        return Poly(std::vector<Z>(a.begin() + k, a.end()));
    }
    friend Poly operator + (const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }
    friend Poly operator - (const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }
    friend Poly operator * (Poly a, Poly b) {
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) {
            sz *= 2;
        }
        a.a.resize(sz); b.a.resize(sz);
        dft(a.a); dft(b.a);
        for (int i = 0; i < sz; ++i) {
            a.a[i] = a[i] * b[i];
        }
        idft(a.a);
        a.resize(tot);
        return a;
    }
    friend Poly operator * (Z a, Poly b) {
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator * (Poly a, Z b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    friend Poly operator / (Poly a, Poly b) {
        int n = a.size(), m = b.size();
        if (n < m) {
            return Poly();
        }
        std::reverse(a.a.begin(), a.a.end());
        std::reverse(b.a.begin(), b.a.end());
        a.resize(n - m + 1);
        b.resize(n - m + 1);
        Poly c = a * b.inv(n - m + 1);
        c.resize(n - m + 1);
        std::reverse(c.a.begin(), c.a.end());
        return c;
    }
    friend Poly operator % (Poly a, Poly b) {
        return a - a / b * b;
    }
    Poly &operator += (Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator -= (Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator *= (Poly b) {
        return (*this) = (*this) * b;
    }
    Poly &operator *= (Z b) {
        return (*this) = (*this) * b;
    }
    Poly &operator /= (Poly b) {
        return (*this) = (*this) / b;
    }
    Poly &operator %= (Poly b) {
        return (*this) = (*this) % b;
    }
    Poly deriv() const { // 求导
        if (a.empty()) {
            return Poly();
        }
        std::vector<Z> res(size() - 1);
        for (int i = 1; i < size(); i++) {
            res[i - 1] = a[i] * i;
        }
        return Poly(res);
    }
    Poly integr() const {
        std::vector<Z> res(size() + 1);
        for (int i = 0; i < size(); i++) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
    Poly inv(int m) const {
        Poly x{a[0].inv()};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const {
        return (deriv() * inv(m)).integr().modxk(m);
    }
    Poly exp(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly pow(int k, int m) const {
        int i = 0;
        while (i < size() && a[i].val() == 0) {
            i++;
        }
        if (i == size() || 1LL * i * k >= m) {
            return Poly(std::vector<Z>(m));
        }
        Z v = a[i];
        auto f = divxk(i) * v.inv();
        return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
    }
    Poly sqrt(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((P + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const { // 
        if (b.size() == 0) {
            return Poly();
        }
        int n = b.size(); // eb + 1
        std::reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1); //保留系数(x ^ eb)及以上的
    }
    std::vector<Z> eval(std::vector<Z> x) const { // 求多项式在x处的值
        if (size() == 0) {
            return std::vector<Z>(x.size(), 0);
        }
        const int n = std::max(int(x.size()), size());
        std::vector<Poly> q(4 * n);
        std::vector<Z> ans(x.size());
        x.resize(n);
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = Poly{1, -x[l]};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        std::function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
            if (r - l == 1) {
                if (l < int(ans.size())) {
                    ans[l] = num[0];
                }
            } else {
                int m = (l + r) / 2;
                work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
            }
        };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};

struct Comb { // 组合数
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {  // C(n, m)
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
};

int main() {
    int n, m; std::cin >> n >> m;
    Poly a, b; a.resize(n + 1); b.resize(m + 1);
    for (int i = 0; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i <= m; i++) {
        std::cin >> b[i];
    }
    Poly c = a / b;
    c.resize(n - m + 1);
    for (int i = 0; i <= n - m; i++) {
        std::cout << c[i] << " \n"[i == n - m];
    }
    auto d = a % b;
    d.resize(m);
    for (int i = 0; i < m; i++) {
        std::cout << d[i] << " \n"[i == m - 1];
    }
    return 0;
}
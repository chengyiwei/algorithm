#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int P = 998244353;
constexpr int INF = 1e9;

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

template<class T>
T qpow(T a, i64 b) {
    return power(a, b);
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

Z rnd() {
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, P - 1);
    return Z(dist(rng));
}

struct Lazy {
    Z mul{ 1 };   // 乘法标记
    Z add{ 0 };   // 加法标记
    void apply(const Lazy& o)& {
        mul *= o.mul;
        add = add * o.mul + o.add;
    }
};

struct Info {
    Z sum{ 0 };
    int len{ 1 };
    int min_val{ INF };
    int max_val{ -INF };
    void apply(const Lazy& o)& {
        sum *= o.mul;   
        sum += o.add * len;
        min_val = min_val * o.mul.val() + o.add.val();
        max_val = max_val * o.mul.val() + o.add.val();
    }
};

Info operator + (const Info& L, const Info& R) {
    return { L.sum + R.sum, L.len + R.len , min(L.min_val, R.min_val), max(L.max_val, R.max_val) };
}

template<class Info, class Lazy>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Lazy> tag;

    LazySegmentTree() {}
    LazySegmentTree(int n) { init(n); }
    LazySegmentTree(const vector<Info> &a) { init(a); }

    void init(int n) {
        this->n = n;
        info.assign(4 * n, Info());
        tag.assign(4 * n, Lazy());
    }

    void init(const vector<Info> &a) {
        init((int)a.size());
        build(1, 0, n, a);
    }

    void build(int p, int l, int r, const vector<Info> &a) {
        if (r - l == 1) {
            info[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m, r, a);
        pull(p);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Lazy &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Lazy(); // clear
    }

    void update(int L, int R, const Lazy &v) { update(1, 0, n, L, R, v); }

    void update(int p, int l, int r, int L, int R, const Lazy &v) {
        if (R <= l || r <= L) return;
        if (L <= l && r <= R) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        update(p << 1, l, m, L, R, v);
        update(p << 1 | 1, m, r, L, R, v);
        pull(p);
    }

    Info query(int L, int R) { return query(1, 0, n, L, R); }

    Info query(int p, int l, int r, int L, int R) {
        if (R <= l || r <= L) return Info({0, 0});
        if (L <= l && r <= R) return info[p];
        push(p);
        int m = (l + r) / 2;
        return query(p << 1, l, m, L, R) + query(p << 1 | 1, m, r, L, R);
    }
};

int main() {
    Z po = rnd();
    // cout << po << "\n";
    Z ne = 1 / po;

    int N, Q;
    cin >> N >> Q;

    vector<Info> a(N), b(N), c(N);
    for (auto n = 0; n < N; n++) {
        int x;
        cin >> x;
        x *= 2;
        a[n] = { x };
        a[n].min_val = x; a[n].max_val = x;
        b[n] = { qpow(po, x) };
        c[n] = { qpow(ne, x) };
    }

    LazySegmentTree<Info, Lazy> sumseg(a);
    LazySegmentTree<Info, Lazy> poseg(b);
    LazySegmentTree<Info, Lazy> neseg(c);

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int L, R, v;
            cin >> L >> R >> v;
            v *= 2;
            L--;
            poseg.update(L, R, { qpow(po, v), 0 });
            neseg.update(L, R, { qpow(ne, v), 0 });
            sumseg.update(L, R, { 1, v });
        } else {
            int L, R;
            cin >> L >> R;
            assert(R - L + 1 > 0 && (R - L + 1) % 2 == 0);
            L--;

            auto sum = sumseg.query(L, R).sum;
            auto c = sum / (R - L);

            auto mn = sumseg.query(L, R).min_val;
            auto mx = sumseg.query(L, R).max_val;
            // cout << mn << " " << mx << "\n";

            auto pores = poseg.query(L, R).sum;
            auto neres = neseg.query(L, R).sum;

            auto A = (pores * qpow(ne, mn)).val();
            auto B = (neres * qpow(po, mx)).val();

            cout << (A == B ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
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

struct Matrix : array<array<Z, 3>, 3> {
    Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                (*this)[i][j] = Z(0);
            }
        }
    }

    friend Matrix operator * (const Matrix &a, const Matrix &b) {
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
};

Matrix qpow(Matrix a, i64 b) {
    Matrix res = Matrix();
    for (int i = 0; i < 3; i++)
        res[i][i] = 1;
    while (b) {
        if (b & 1) { res = res * a; }
        a = a * a;
        b = b >> 1;
    }
    return res;
}

void solve() {
    i64 n, m; cin >> n >> m;
    if (n == 1) {
        cout << 1 << '\n';
        return ;
    }

    Z g = power(Z(2), m) - Z(1);

    Matrix A;
    A[0][0] = -g; A[0][2] = g + 1; A[1][0] = 1; A[2][2] = g * g;

    Matrix a0;
    i64 exp;
    if (n % 2 == 0) {
        a0[0][0] = 0;
        a0[1][0] = 0;
        a0[2][0] = g * g;
        exp = (n - 2) / 2;
    }
    else {
        a0[0][0] = g * g;
        a0[1][1] = 0;
        a0[2][0] = g * g * g;
        exp = (n - 3) / 2;
    }

    Matrix ans = qpow(A, exp) * a0;
    cout << ans[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {solve();}

    return 0;
}

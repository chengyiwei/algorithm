#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7; 

struct Matrix {
    int n, m;
    vector<vector<ll>> a;
    Matrix(int n = 0, int m = 0) : n(n), m(m) {
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            fill(a[i].begin(), a[i].end(), 0);
        }
    }
};

Matrix operator * (Matrix &A, Matrix &B) {
    Matrix C(A.n, B.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < B.m; j++)
            for (int k = 0; k < A.m; k++) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % TT;
                C.a[i][j] %= TT;
            }
    return C;
}

Matrix fastpow (Matrix A, ll b) {
    Matrix res(A.n, A.m);
    for (int i = 0; i < A.n; i++) res.a[i][i] = 1;
    while (b) {
        if (b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}

int main() {
    freopen ("A.in", "r", stdin);
    ll n, m; cin >> n >> m;
    if (n < m) return cout << 1 << endl, 0;
    Matrix A(m, m);
    A.a[0][0] = 1; A.a[0][m - 1] = 1;
    for (int i = 1; i < m; i++) A.a[i][i - 1] = 1;
    auto B = fastpow(A, n - m);
    Matrix M(m, 1);
    M.a[0][0] = 2;
    for (int i = 1; i < m; i++) M.a[i][0] = 1;
    auto ans = B * M;
    cout << ans.a[0][0] << endl;
    return 0;
}
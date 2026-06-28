#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL TT = 10000;

struct Matrix {
    int n, m;
    vector<vector<int>> a;
    Matrix(int n, int m) : n(n), m(m), a(n, vector<int>(m, 0)) {}
    Matrix operator* (const Matrix &b) const {
        Matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    c.a[i][j] = (c.a[i][j] + 1ll * a[i][k] * b.a[k][j] % TT ) % TT;
                }
            }
        }
        return c;
    }
};

Matrix qpow(Matrix a, LL b) {
    Matrix ret(a.n, a.m);
    for (int i = 0; i < a.n; i++) ret.a[i][i] = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

int main(){
    int x;
    while (cin >> x) {
        if (x == -1) break;
        Matrix a(2, 2); a.a[0][0] = 1; a.a[0][1] = 1; a.a[1][0] = 1; a.a[1][1] = 0;
        Matrix b(2, 1); b.a[0][0] = 1; b.a[1][0] = 0;
        a = qpow(a, x);
        a = a * b;
        cout << a.a[1][0] << '\n';
    }
    return 0;
}
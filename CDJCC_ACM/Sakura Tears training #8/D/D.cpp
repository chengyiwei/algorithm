#include <bits/stdc++.h>
using namespace std;
#define int long long

const int TT = 1e9 + 7;

struct Martix {
    int n = 100;
    int a[105][105];
    Martix() {
        memset(a, 0, sizeof(a));
    }
    Martix operator * (const Martix &rhs) const {
        Martix res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * rhs.a[k][j]) % TT;
        return res;
    }
    void print(int x) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
};

signed main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    Martix A;
    for (int i = 0; i < m; i++) A.a[i][0] = 1;
    Martix W;
    for (int i = 1; i < m; i++) W.a[i][i - 1] = 1;
    W.a[0][0] = W.a[0][m - 1] = 1;

    while (n) {
        if (n & 1) A = W * A;
        W = W * W;
        n >>= 1;
    }

    cout << A.a[m - 1][0] << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, S, k; cin >> n >> S >> k;
    vector<LL> a(n + 1);
    int m = 2 * k + 1;
    if (k == 0) {
        S -= n;
        if (S < 0) {
            cout << -1 << endl;
            return;
        }
        for (int i = 1; i <= n; i++) 
            a[i] = 1;
        a[1] += S;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    if (n < m) {
        cout << -1 << endl;
        return;
    }
    else if (n == m) {
        LL sum_1 = k * 1, sum_2 = (k + 1) * 2;
        S -= sum_1 + sum_2;
        if (S < 0) {
            cout << -1 << endl;
            return;
        }
        LL x = S / (k + 1); S -= x * (k + 1);
        for (int i = 1; i <= m; i += 2) {
            a[i] = 2 + x;
        }
        for (int i = 2; i <= m; i += 2) {
            if (S > 0) {
                if (x == 0) {
                    cout << -1 << endl;
                    return;
                }
                a[i] = 2; S -= 1;
            }
            else a[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else if (n > m) {
        LL sum_1 = k * 1, sum_2 = (k + 1) * 2;
        S -= sum_1 + sum_2;
        for (int i = 1; i <= m; i++) {
            if (i & 1) a[i] = 2;
            else a[i] = 1;
        }
        for (int i = m + 1; i <= n; i++) {
            a[i] = 1; S -= 1;
        }
        if (S < 0) {
            cout << -1 << endl;
            return;
        }
        a[m + 1] += S;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
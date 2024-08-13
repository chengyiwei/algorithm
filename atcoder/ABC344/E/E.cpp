#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    unordered_map<int,int> right, left;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i != 1) left[a[i]] = a[i - 1];
        if (i != n) right[a[i]] = a[i + 1];
    }
    left[a[1]] = -INF; right[a[n]] = INF;
    left[INF] = a[n]; right[-INF] = a[1];
    int q; cin >> q;
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x, y; cin >> x >> y;
            const int L = x, R = right[x];
            left[y] = L; right[y] = R;
            right[L] = y; left[R] = y;
        }
        if (opt == 2) {
            int x; cin >> x;
            const int L = left[x], R = right[x];
            right[L] = R; left[R] = L;
            left.erase(x); right.erase(x);
        }
    }
    int x = right[-INF];
    while (x != INF) {
        cout << x << " ";
        x = right[x];
    }
    return 0;
}
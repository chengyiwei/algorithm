#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> &a) {
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] > a[i]) ret++;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    int ans = 1e9;
    do {
        vector<int> c;
        for (int i = 0; i < n; i++) {
            c.push_back(a[b[i]][0]);
            c.push_back(a[b[i]][1]);
        }
        int now = calc(c);
        ans = min(ans, now);
    } while (next_permutation(b.begin(), b.end()));
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
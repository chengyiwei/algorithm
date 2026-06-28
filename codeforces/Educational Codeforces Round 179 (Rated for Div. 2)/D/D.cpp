#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    deque<int> f(m , 0);
    ll ans = 0;
    for (int i = 0; i < m; i++) cin >> f[i];
    sort(f.begin(), f.end());
    vector<array<int, 2>> p(n + 1, {0, 0});
    for (int i = 1; i <= n; i += 2) {
        if (f.size() == 1) {
            int tmp = f.front(); f.pop_front();
            p[i] = {tmp, tmp};
        }
        else {
            int tmp1 = f.front(), tmp2 = f.back();
            f.pop_front(); f.pop_back();
            p[i] = {tmp1, tmp2};
            if (i + 1 <= n)
                p[i + 1] = {tmp2, tmp1};
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 6; j++) {
            cout << p[i][j % 2] << " ";
            if (j != 6) ans += abs(p[i][j % 2] / 100 - p[i][(j + 1) % 2] / 100);
        }
        cout << "\n";
    }
    // cout << ans << "\n";
}

int main() {
    // freopen("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}
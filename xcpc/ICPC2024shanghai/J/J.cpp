#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int vis[MAXN];

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (vis[i]) continue;
        for (int j = i + i; j < MAXN; j += i)
            vis[j] = 1;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for (int L = 1; L <= n; L++) {
        for (int i = 1; i + L - 1 <= n; i++) {
            int j = i + L - 1;
            int s = sum[j] - sum[i - 1];
            if (vis[s]) {
                cout << L - 1 << '\n';
                return ;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(0);
    init();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
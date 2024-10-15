#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int fa[MAXN], cf[MAXN][11];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        for (int j = 1; j <= 10; j++) cf[i][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int a, k, d; cin >> a >> d >> k;
        cf[a][d] += 1; cf[a + k * d][d] -= 1;
    }

    for (int j = 1; j <= 10; j++) {
        for (int i = 1; i <= n; i++) {
            if (i - j >= 0) cf[i][j] += cf[i - j][j];
            if (cf[i][j] > 0) {
                int x = find(i), y = find(i + j);
                if (x != y) fa[x] = y;
            }
        }
    }


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            ans += 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
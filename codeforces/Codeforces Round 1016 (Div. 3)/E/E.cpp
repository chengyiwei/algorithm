#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> b(n + 1, 0);

    auto check = [&] (int m) {
        if (m == 0) return true;
        int cnt = 0, now = 0;
        for (int i = 0; i < m; i++)
            b[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < m && b[a[i]] == 0) {
                b[a[i]] = 1;
                now += 1;
            }
            if (now == m) {
                cnt += 1;
                now = 0;
                for (int j = 0; j < m; j++)
                    b[j] = 0;
            }
        }
        return cnt >= k;
    };

    int L = 0, R = n + 1;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    cout << L << '\n';
    return ;
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
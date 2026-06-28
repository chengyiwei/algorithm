#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    if (n > m) swap(n, m), swap(a, b);
    vector<int> cnta(26, 0), cntb(26, 0);
    for (int i = 0; i < n; i++) cnta[a[i] - 'a']++;
    for (int i = 0; i < m; i++) cntb[b[i] - 'a']++;

    auto check = [&] () {
        for (int i = 0; i < 26; i++) {
            int x = min(cnta[i], cntb[i]);
            cnta[i] -= x; cntb[i] -= x;
        }
    };

    check();

    int ret = (n + m) / 2 - n;
    for (int i = 0; i < 26; i++) {
        while (cntb[i] >= 2) {
            cntb[i] -= 2;
            if (--ret == 0) break;
        }
        if (ret == 0) break;
    }

    int sum = -ret;

    for (int i = 0; i < 26; i++) sum += cntb[i];
    if ((n + m) % 2 == 1) sum -= 1;
    assert(sum >= 0);
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}
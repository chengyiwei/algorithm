#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<string> t(n + 1);

    auto check = [&] (vector<string> &t) {
        vector<int> cnt(m + 1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < m; j++)
                cnt[j] += t[i][j] - '0';
         return (*max_element(cnt.begin(), cnt.end())) <= 1;
    };

    int cnt = 0;
    for (int S = 0; S < (1 << n); S++) {
        for (int i = 1; i <= n; i++) {
            t[i] = s[i];
            if (S >> (i - 1) & 1)
                reverse(t[i].begin(), t[i].end());
        }
        if (check(t))
            cnt ++;
    }
    cout << cnt << endl;
}

int main() {
    freopen ("in.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) 
        solve();
    return 0;
}
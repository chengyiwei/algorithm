#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int min_idx = min_element(a.begin() + 1, a.end()) - a.begin();
    int max_idx = max_element(a.begin() + 1, a.end()) - a.begin();

    vector<int> s(n + 1, 0);

    auto check = [&] (int L, int R) {
        if (L > R) swap(L, R);
        int max_val = max(a[L], a[R]), min_val = min(a[L], a[R]);
        for (int i = L + 1; i < R; i++) {
            if (a[i] > min_val && a[i] < max_val) s[i] = 1;
        }
    };

    check(1, min_idx);
    check(1, max_idx);
    check(min_idx, n);
    check(max_idx, n);
    check(min_idx, max_idx);

    string t; cin >> t;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '1' && s[i + 1] == 0) {
            cout << -1 << "\n";
            return ;
        }
    }

    cout << 5 << "\n";
    cout << 1 << " " << min_idx << "\n";
    cout << 1 << " " << max_idx << "\n";
    cout << min_idx << " " << n << "\n";
    cout << max_idx << " " << n << "\n";
    cout << min(min_idx, max_idx) << " " << max(min_idx, max_idx) << "\n";
}

int main() {
    // freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)  solve();
}
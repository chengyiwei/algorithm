#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("B.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m_ = *max_element(a.begin(), a.end());
        while (m--) {
            char op; cin >> op;
            int l, r; cin >> l >> r;
            if (op == '+' && l <= m_ && m_ <= r) m_ += 1;
            else if (op == '-' && l <= m_ && m_ <= r) m_ -= 1;
            cout << m_ << ' ';
        }
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> stk;
    pre[0] = -1;
    int pre_max_idx = 0;
    for (int i = 1; i < n; i++) {
        pre[i] = pre_max_idx;
        if (a[i] >= a[pre_max_idx]) pre_max_idx = i;
    }
    pre[n] = pre_max_idx;
    int pos = n, cnt = 0;
    while (pos > 0) {
        pos = pre[pos];
        cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
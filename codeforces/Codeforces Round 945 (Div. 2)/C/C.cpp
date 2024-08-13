#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    auto check = [&] (int fst, vector<int> &b) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = fst; i < n; i += 2) {
            if (i <= 1) continue;
            pq.push(a[i]);
        }
        int cnt = n;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            b[pos[x]] = cnt--;
        }
        cnt = 1;
        for (int i = fst - 1; i <= n; i += 2) {
            if (i <= 0) continue;
            pq.push(-a[i]);
        }
        while (!pq.empty()) {
            int x = -pq.top(); pq.pop();
            b[pos[x]] = cnt++;
        }
        if (b[1] == 0) b[1] = cnt++;
        if (b[n] == 0) b[n] = cnt++;
        vector<int> c(n + 1, 0);
        for (int i = 1; i <= n; i++) c[i] = a[i] + b[i];
        int ret = 0;
        for (int i = 2; i < n; i++) {
            if (c[i] > c[i - 1] && c[i] > c[i + 1]) ret++;
        }
        return ret;
    };

    vector<int> b1(n + 1, 0), b2(n + 1, 0);
    int ans2 = check(3, b2);
    int ans1 = check(2, b1);
    // cout << ans1 << " " << ans2 << endl;
    if (ans1 > ans2) {
        for (int i = 1; i <= n; i++) cout << b1[i] << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++) cout << b2[i] << " ";
        cout << endl;
    }
}

int main() {
    freopen("C.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
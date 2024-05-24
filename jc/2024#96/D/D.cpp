#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 30; j >= 0; j--) {
            if (a[i] % (1 << j) == 0) {
                cnt += j;
                break;
            }
        }
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 30; j >= 0; j--)
            if (i % (1 << j) == 0) {
                pq.push(j);
                break;
            }
    }
    int ans = 0;
    while (!pq.empty()) {
        if (cnt < n) {
            cnt += pq.top();
            pq.pop();
            ans += 1;
        }
        else break;
    }

    if (cnt >= n)
        cout << ans << '\n';
    else
        cout << "-1\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}
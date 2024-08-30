#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int INF = 0x3f3f3f3f;
signed main() {
    freopen ("K.in", "r", stdin);
    freopen ("K.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (k == 1) {
        cout << *max_element(a.begin() + 1, a.end()) << endl;
        return 0;
    }

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        while (x) { p.push_back(x); x /= k; }
    }
    p.push_back(0);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    reverse(p.begin(), p.end());
    int ans = INF, cnt = 0;
    int pos = 1;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) pq.push(a[i]);
    for (auto x : p) {
        while (!pq.empty() && pq.top() > x) {
            cnt += 1;
            int tmp = pq.top(); pq.pop();
            pq.push(tmp / k);
        }
        ans = min(ans, x + cnt);
    }

    cout << ans << endl;
    return 0;
}

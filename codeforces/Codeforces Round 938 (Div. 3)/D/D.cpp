#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e6 + 5;
int cnt_a[maxn], cnt_b[maxn];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i], cnt_a[a[i]] += 1;
    
    int now_k = 0;

    auto insert = [&] (int x) {
        cnt_b[x] ++;
        if (cnt_b[x] <= cnt_a[x]) now_k ++;
    };

    auto del = [&] (int x) {
        if (cnt_b[x] <= cnt_a[x]) now_k --;
        cnt_b[x] --;
    };

    for (int i = 1; i <= m; i++) 
        insert(b[i]);
    int ans = now_k >= k;
    for (int i = m + 1; i <= n; i++) {
        del(b[i - m]);
        insert(b[i]);
        ans += now_k >= k;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cnt_b[b[i]] = 0;
    for (int i = 1; i <= m; i++) cnt_a[a[i]] = 0;
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
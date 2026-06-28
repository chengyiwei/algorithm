#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> b_id(n + 1);
    for (int i = 1; i <= n; i++)
        b_id[b[i]] = i;

    vector<pair<int, int>> ans; 

    auto swap = [&] (int x, int y) {
        if (x == y) return ;
        ans.push_back({x, y});
        int tmp = a[x];
        a[x] = a[y]; a[y] = tmp;

        tmp = b[x];
        b[x] = b[y]; b[y] = tmp;

        b_id[b[x]] = x; b_id[b[y]] = y;
    };

    int same = 0, same_i = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            same += 1;
            same_i = i;
        }
    }
    if (same > 1 || (same == 1 && n % 2 == 0)) {
        cout << -1 << '\n';
        return ;
    }
    if (same == 1) {
        swap(same_i, (n + 1) / 2);   
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[n + 1 - i]) continue;
        swap(b_id[a[i]], n + 1 - i);
    }

    int flg = 1;
    for (int i = 1; i <= n; i++) 
        if (a[i] != b[n + 1 - i]) flg = 0;
    
    if (flg == 0) {
        cout << -1 << '\n';
        return ;
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }

    return ;
} 

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}
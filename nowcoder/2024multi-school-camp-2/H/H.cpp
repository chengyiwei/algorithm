#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int flg[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H.out", "w", stdout);
    int n, X, Y; cin >> n >> X >> Y;

    if (X == 0 && Y == 0)
        return cout << 1ll * n * (n + 1) / 2 << endl, 0;

    vector<int> a(n + 1);
    vector<pii> pos(n + 1); 
    map<pii, vector<int>> mp; 
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        if (ch == 'w') a[i] = 0;
        if (ch == 'D') a[i] = 1;
        if (ch == 'S') a[i] = 2;
        if (ch == 'A') a[i] = 3;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        x += flg[a[i]][0]; y += flg[a[i]][1];
        pos[i] = {x, y};
        mp[pos[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        auto [x, y] = pos[i - 1];
        int x_ = X + x, y_ = Y + y;
        if (!mp.count({x_, y_})) continue;
        auto it = lower_bound(mp[{x_, y_}].begin(), mp[{x_, y_}].end(), i);
        if (it != mp[{x_, y_}].end()) {
            ans += n - *it + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

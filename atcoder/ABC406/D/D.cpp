#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int H, W;   cin >> H >> W;
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    vector<vector<int>> row(H + 1, vector<int>());
    vector<vector<int>> col(W + 1, vector<int>());

    for (int i = 0; i < n; i++) {
        row[p[i].first].push_back(i);
        col[p[i].second].push_back(i);
    }

    vector<int> vis(n, 0);
    int Q; cin >> Q;
    map<pair<int, int>, int> mp;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            if (mp.find({1, x}) != mp.end()) {
                mp[{1, x}] = 1;
                cout << 0 << '\n';
                continue;
            }
            int ans = 0;
            for (auto i : row[x]) {
                if (vis[i] == 0) {
                    ans++;
                    vis[i]  += 1;
                }
            }
            cout << ans << '\n';
        }
        else {
            int y; cin >> y;
            if (mp.find({2, y}) != mp.end()) {
                mp[{2, y}] = 1;
                cout << 0 << '\n';
                continue;
            }
            int ans = 0;
            for (auto i : col[y]) {
                if (vis[i] == 0) {
                    ans++;
                    vis[i] += 1;
                }
            }
            cout << ans << '\n';
        }
    }

    for (int i = 0; i < n; i++) 
        assert(vis[i] <= 2);

    return 0;
}
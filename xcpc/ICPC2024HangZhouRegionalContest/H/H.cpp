#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end(), [](auto &x, auto &y) {
        return x.first - x.second < y.first - y.second;
    });

    auto len = [&] (pair<int, int> &x) {
        return x.second - x.first + 1;
    };

    vector<int> fa(n + 1, 0);
    if (k == 1) {
        for (int i = a[1].first + 1; i <= a[1].second; i++)
            fa[i] = i - 1;
    }
    else {
        if (len(a[1]) == len(a[2])) {
            if (len(a[k]) <= len(a[1]) - 2) {
                int root = a[1].first; fa[root] = 0;
                for (int i = a[1].first + 1; i <= a[1].second; i++) 
                    fa[i] = i - 1;
                for (int i = a[k].first + 1; i <= a[k].second; i++)
                    fa[i] = i - 1;
                fa[a[k].first] = a[1].first + 1;
                for (int i = 2; i <= k - 1; i++) {
                    for (int j = a[i].first + 1; j <= a[i].second; j++)
                        fa[j] = j - 1;
                    fa[a[i].first] = root;
                }
            }
            else {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
        else {
            int root = a[1].first; fa[root] = 0;
            for (int i = a[1].first + 1; i <= a[1].second; i++)
                fa[i] = i - 1;
            for (int i = 2; i <= k; i++) {
                for (int j = a[i].first + 1; j <= a[i].second; j++)
                    fa[j] = j - 1;
                fa[a[i].first] = root;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << fa[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
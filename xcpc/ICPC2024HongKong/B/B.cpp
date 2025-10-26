#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    
    int k; cin >> k;
    vector<int> cost(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> cost[i];
    vector<int> f(m + 1, INF), g(m + 1, 0);
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= k; i++) 
            if (j - i >= 0) {
                if (f[i] < f[j - i] + cost[i]) {
                    
                }
            }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int N, M, W; cin >> N >> M >> W;
    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    vector<int> fa(N + 1);
    iota(fa.begin(), fa.end(), 0);

    function<int(int)> find = [&](int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };

    for (int i = 1; i <= M; i++) {
        int x, y; cin >> x >> y;
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }

    for (int i = 1; i <= N; i++) {
        int f = find(i);
        if (f != i) {
            w[f] += w[i];
            v[f] += v[i];
            w[i] = v[i] = 0;
        }
    }

    vector<int> dp(W + 1);
    for (int i = 1; i <= N; i++) {
        if (w[i] == 0) continue;
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
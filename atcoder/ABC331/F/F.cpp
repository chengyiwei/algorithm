#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
const int maxn = 5005;
vector<int> G[maxn];
int w[maxn], id[maxn];
LL a[maxn], f[maxn], g[maxn];
int main() {
    // freopen("F.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]), id[i] = i;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(id + 1, id + n + 1, [&](int x, int y) { return w[x] < w[y]; });
    for (int i = 1; i <= n; i++) {
        int u = id[i];
        memset(f, 0, sizeof(f));
        for (auto v : G[u]) {
            if (w[u] > w[v]) {
                for (int j = w[u] - 1; j >= w[v]; j--) {
                    f[j] = max(f[j], f[j - w[v]] + g[v]);
                }
            }
        }
        for (int j = 0; j <= w[u] - 1; j++) {
            g[u] = max(g[u], f[j]);
        }
        g[u] += 1;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * g[i];
    printf("%lld\n", ans);
    return 0;
}
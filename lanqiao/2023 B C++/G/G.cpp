#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
vector<pii> g[maxn];
int f[maxn][20], dep[maxn];
ll sum[maxn];
ll b[maxn];
int a[maxn];

int n, k;
void dfs (int u, int fa) {
	f[u][0] = fa;
	for (auto e : g[u])
		if (e.first != fa) {
			sum[e.first] = sum[u] + e.second;
			dep[e.first] = dep[u] + 1;
			dfs (e.first, u);
		}
}

void init() {
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
}

int lca (int u, int v) {
	if (dep[u] > dep[v]) swap (u, v);
	for (int j = 19; j >= 0; j--)
		if (dep[f[v][j]] >= dep[u]) 
			v = f[v][j];
	if (u == v) return u;
	for (int j = 19; j >= 0; j--)
		if (f[u][j] != f[v][j])
			u = f[u][j], v = f[v][j];
	return f[u][0];
}

int main() {
	freopen ("G.in", "r", stdin);
	scanf ("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf ("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, 0);
	init();
	ll s = 0;
	for (int i = 1; i <= k; i++)
		scanf ("%d", &a[i]); 
	for (int i = 1; i < k; i ++) {
		int l = lca(a[i], a[i + 1]);
		b[i] = sum[a[i]] + sum[a[i + 1]] - 2 * sum[l];
		s += b[i];
	}
	for (int i = 1; i <= k; i++) {
		ll ans = s;
		if (i < k) ans -= b[i];
		if (i > 1) ans -= b[i - 1];
		if (i < k && i > 1) {
			int l = lca(a[i - 1], a[i + 1]); 
			ans += sum[a[i - 1]] + sum[a[i + 1]] - 2 * sum[l];
		}
		printf ("%lld ", ans);
	}
	return 0;
	
} 

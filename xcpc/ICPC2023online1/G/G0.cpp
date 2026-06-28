#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 3;
const int mod = 998244353;
ll fp(ll ba, ll ec)
{
    ll res = 1;
    for (; ec > 0; ec >>= 1)
    {
        if (ec & 1)
            res = res * ba % mod;
        ba = ba * ba % mod;
    }
    return res;
}
vector<int> e[N];
array<int, 2> a[N];
int fa[N];
void dfs(int u)
{
    for (int &v : e[u])
    {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs(v);
    }
}
int f[N], low[N], sz[N];
int find(int x)
{
    return f[x] == 0 ? x : (f[x] = find(f[x]));
}
int main()
{
    freopen ("G.in", "r", stdin);
    freopen ("G0.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
        low[i] = i;
    fill(sz + 1, sz + n + 1, 1);
    ll ans = 1;
    for (int i = 1; i < n; ++i)
    {
        int u = find(a[i][0]), v = find(a[i][1]);
        if (v == find(fa[low[u]]))
        {
        }
        else if (u == find(fa[low[v]]))
            low[v] = low[u];
        else
        {
            cout << 0;
            return 0;
        }
        ans = ans * (ll)sz[u] % mod * (ll)sz[v] % mod;
        sz[v] += sz[u];
        f[u] = v;
    }
    cout << fp(ans, mod - 2) << '\n';
    return 0;
}
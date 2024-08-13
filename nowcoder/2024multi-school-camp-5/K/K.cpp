#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
typedef long long ll;

int cnt = 1;
struct Node {
    int fa, val;
}t[MAXN];

map<int, int> G;

void build (int u, int fa, vector<int> a) {
    t[u].fa = fa;
    if (a.size() == 1) {
        G[a[0]] = u; t[u].val = a[0]; return;
    }
    int L = a.front(), R = a.back(), mid = (L + R) >> 1;
    vector<int> l, r;
    t[u].val = mid;
    for (auto x : a) {
        if (x <= mid) l.push_back(x);
        else r.push_back(x);
    }
    if (!l.empty()) build(++cnt, u, l);
    if (!r.empty()) build(++cnt, u, r);
}

ll get(int ai) {
    int u = G[ai];
    ll res = 0;
    while (u) {
        res += abs(t[u].val - ai);
        u = t[u].fa;
    }
    return res;
}

int main() {
    freopen ("K.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    build(cnt, 0, a);
    ll ans = 0;
    for (auto x : a) 
        ans = max(ans, get(x));
    cout << ans << '\n';
    return 0;
}
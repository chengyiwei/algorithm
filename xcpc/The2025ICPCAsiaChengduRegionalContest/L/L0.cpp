#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2e5 + 5;

multiset<int> a[MAXN];
multiset<int> b[MAXN];

multiset<int> * pa[MAXN];
multiset<int> * pb[MAXN];

int a0[MAXN];
int b0[MAXN];

int n;
int A[MAXN], B[MAXN];
vector<int> mp[MAXN];

void check (multiset<int> * x, multiset<int> * y) {
    int flg = 0;
    if (x->size() < y->size()) {swap(x, y); flg = 1;}
    auto it = y->begin();
    while (it != y->end()) {
        auto _ = *it;
        if (x->count(_)) {
            x->erase(x->find(_));
            auto nxt = it; ++it;
            y->erase(nxt); 
        }
        else { ++it; }
    }
    if (flg) {swap(x, y);}
};

void  merge (multiset<int> * &x,  multiset<int> * &y) {
    if (x->size() < y->size()) {swap(x, y);}
    auto it = y->begin();
    while (it != y->end()) {
        x->insert(*it);
        ++it;
    }
};

int s[MAXN];

void dfs (int u, int f) {
    if (A[u] == 0) a0[u] += 1;
    else if (A[u] ^ B[u]) pa[u]->insert(A[u]);

    if (B[u] == 0) b0[u] += 1;
    else if (A[u] ^ B[u]) pb[u]->insert(B[u]);
        
    for (auto v : mp[u]) {
        if (v == f) continue;
        dfs(v, u);

        check(pa[u], pb[v]);
        check(pa[v], pb[u]);

        merge(pa[u], pa[v]);
        merge(pb[u], pb[v]);
    
        a0[u] += a0[v]; b0[u] += b0[v];
    }

    // cout << u << " " << pa[u]->size() << " " << b0[u] << " " << pb[u]->size() << " " << a0[u] << "\n";
    if (pa[u]->size() <= b0[u] and pb[u]->size() <= a0[u]) s[u] = 1;
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= n; i++) mp[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        mp[u].push_back(v); mp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        a[i].clear(); b[i].clear();
        pa[i] = &a[i]; pb[i] = &b[i];
        a0[i] = b0[i] = 0;
        s[i] = 0;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        cout << s[i];
    cout << '\n';
}

int main() {
    // freopen ("L.in", "r", stdin);
    // freopen ("L.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
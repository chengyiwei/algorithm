#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 7;

struct DSU {
    vector<ll> fa;
    vector<ll> diff; 
    vector<bool> has_val;
    vector<ll> val;   
    
    DSU(ll n) {
        fa.resize(n + 1);
        diff.resize(n + 1, 0);
        has_val.resize(n + 1, false);
        val.resize(n + 1, 0);
        for (ll i = 1; i <= n; i ++) fa[i] = i;
    }
    
    ll find(ll x) {
        if (fa[x] != x) {
            ll root = find(fa[x]);
            diff[x] += diff[fa[x]];
            fa[x] = root;
        }
        return fa[x];
    }
    
    bool merge(ll u, ll v, ll k) {
        ll ru = find(u), rv = find(v);
        if (ru == rv) {
            return (diff[u] - diff[v]) == k;
        }
        
        if (has_val[ru] && has_val[rv]) {
            ll actual_u = val[ru] + diff[u];
            ll actual_v = val[rv] + diff[v];
            if (actual_u - actual_v != k) return false;
        }
        
        fa[rv] = ru;
        diff[rv] = diff[u] - diff[v] - k;
        
        if (has_val[rv] && !has_val[ru]) {
            has_val[ru] = true;
            val[ru] = val[rv] + diff[rv];
        }
        
        
        return true;
    }
    
    bool set_val(ll u, ll k) {
        ll ru = find(u);
        
        if (has_val[ru]) {
            ll cur_val = val[ru] + diff[u];
            if (cur_val != k) return false;
            return true; 
        }
        
        has_val[ru] = true;
        val[ru] = k - diff[u];
        return true;
    }
    
    pair<bool, ll> query(ll u, ll v) {
        ll ru = find(u), rv = find(v);
        if (ru != rv) return {false, 0};
        return {true, diff[u] - diff[v]};
    }
};

ll Tex = 1, n, q;
void AC() {
    cin >> n >> q;
    DSU dsu(n);
    
    while (q --) {
        ll op, u, v;
        ll k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v >> k;
            if (dsu.merge(u, v, k)) cout << "OK\n";
            else cout << "CONTRADICTION\n";
        } else if (op == 2) {
            cin >> u >> k;
            if (dsu.set_val(u, k)) cout << "OK\n";
            else cout << "CONTRADICTION\n";
        } else if (op == 3) {
            cin >> u >> v;
            auto res = dsu.query(u, v);
            if (res.first) cout << res.second << "\n";
            else cout << "UNKNOWN\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> Tex;
    while (Tex --) AC();
    
    return 0;
}
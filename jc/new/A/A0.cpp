#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("A.in", "r", stdin);
    int N, K; cin >> N >> K;
    vector<ll> t(N + 1);
    for (int i = 1; i <= N; i++) cin >> t[i];
    priority_queue<ll> pq;
    vector<vector<ll> > g(N + 1);
    map<ll, int> mp; int cnt = 0;
    
    auto insert = [&](ll x) {
        if (!mp.count(x)) mp[x] = ++cnt;
    };

    for (int i = 1; i <= K; i++) {
        insert(t[i]);
        pq.push(t[i]);
    }
    for (int i = K + 1; i <= N; i++) {
        auto tim = pq.top(); pq.pop();
        pq.push(tim + t[i]);
        insert(tim + t[i]); insert(t[i]);
        g[mp[tim + t[i]]].push_back(mp[t[i]]);
    }
    cout << pq.top() << endl;
    vector<int> vis(cnt + 1, 0);
    function<void(int)> dfs = [&](int x) {
        vis[x] = 1;
        for (auto v : g[x]) {
            if (!vis[v]) dfs(v);
        }
    };
    for (int i = 1; i <= K; i++)
        cout << vis[i];
    return 0;
}
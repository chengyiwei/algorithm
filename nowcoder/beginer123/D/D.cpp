#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18 + 7;
ll Tex = 1, n, m, vis[MAXN], dis[MAXN];
vector<pair<ll, ll>> mp1[MAXN];
vector<pair<ll, ll>> mp[MAXN];
void AC() {
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    ll MX = dis[0];
    for (int i = 1; i <= m; i ++) {
        ll x, y, z;
        cin >> x >> y >> z;
        mp1[x].push_back({y, z});
        mp1[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i ++) {
        ll mn = INF;
        for (auto it : mp1[i]) {
            mn = min(it.second, mn);
        }
        for (auto it : mp1[i]) {
            mp[i].push_back({it.first, min(it.second, mn * 2)});
        }
    }
    // for (int i = 1; i <= n; i ++) {
    //     for (auto it : mp[i]) {
    //         cout << i << " " << it.first << " " << it.second << "\n";
    //     }
    // }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> op;
    op.push({0, 1});
    dis[1] = 0;
    while (!op.empty()) {
        pair<ll, ll> qwq = op.top();
        op.pop();
        if (vis[qwq.second]) continue;
        vis[qwq.second] = 1;
        for (auto it : mp[qwq.second]) {
            if (dis[it.first] > qwq.first + it.second) {
                dis[it.first] = qwq.first + it.second;
                op.push({dis[it.first], it.first});
            }
        }
    }
    if (dis[n] == MX) cout << "-1\n";
    else cout << dis[n] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> Tex;
    while (Tex --) AC();
    return 0;
}
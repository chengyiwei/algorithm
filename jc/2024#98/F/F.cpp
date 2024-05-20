#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll > > p;

bool solve() {
    int n, m; cin >> n >> m;
    p.clear();
    p.push_back({0, 0});
    for (int i = 1; i <= m; i++) {
        ll a, b; cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());
    for (int i = 0; i + 1 < p.size(); i++) {
        ll dis = p[i + 1].first - p[i].first;
        if (dis > p[i + 1].second || dis == p[i + 1].second - p[i].second)
            continue;
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) 
        cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    vector<int> L, R;
    vector<ll> siz;
    for (int i = 0; i < n; i++) {
        if (i != 0 && l[i] == r[i] && L.back() == l[i] && R.back() == r[i]) 
            {siz[siz.size() - 1] += 1;}
        else 
            {L.push_back(l[i]), R.push_back(r[i]), siz.push_back(1);}
    }
    n = L.size();

    map<ll, pair<ll, ll>> pre, now;
    // vector<array<ll, 3>> pre, now;
    now[-1] = {0, 0};

    for (int i = 0; i < n; i++) {
        pre = now; now.clear();
        for (int j = L[i]; j <= min(R[i], L[i] + 2); j++) {
            for (auto [val, _] : pre) {
                auto [ans, len] = _;
                if (j == val) {
                    if (!now.count(j) || now[j].first > ans - len * len + (siz[i] + len) * (siz[i] + len) || (now[j].first == ans - len * len + (siz[i] + len) * (siz[i] + len) && now[j].second > siz[i] + len)) {
                        now[j] = {ans - len * len + (siz[i] + len) * (siz[i] + len), siz[i] + len};
                    }
                }
                else {
                    if (!now.count(j) || now[j].first > ans + siz[i] * siz[i] || (now[j].first == ans + siz[i] * siz[i] && now[j].second > siz[i])) {
                        now[j] = {ans + siz[i] * siz[i], siz[i]};
                    }    
                }
            }
        }
        vector<array<ll, 3>> tmp;
        for (auto [val, _] : now) {
            auto [ans, len] = _;
            tmp.push_back({ans, len, val});
        }
        sort(tmp.begin(), tmp.end());
        tmp.resize(min((tmp.size()), 3ul));
        now.clear();
        for (auto [ans, len, val] : tmp) 
            now[val] = {ans, len};
    }

    ll res = INF;
    for (auto [val, _] : now) { 
        auto [ans, len] = _;
        res = min(ans, res);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
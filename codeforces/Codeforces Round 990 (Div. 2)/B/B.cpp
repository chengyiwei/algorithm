#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    if (cnt.size() == 1) {cout << s << '\n'; return;}

    vector<pair<int, char>> v;
    for (auto p : cnt) {
        v.push_back({p.second, p.first});
    }
    sort(v.begin(), v.end());

    char mx = v.back().second, mi = v[0].second;
    
    for (auto &c : s) {
        if (c == mi) {
            c = mx;
            break;
        }
    }
    cout << s << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
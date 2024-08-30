#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    priority_queue<pair<int, char>> pq;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            pq.push({cnt[i], i + 'a'});
        }
    }
    while (!pq.empty()) {
        auto [num, ch] = pq.top(); pq.pop();
        cout << ch;
        if (--num > 0) pq.push({num, ch});
    }
    cout << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
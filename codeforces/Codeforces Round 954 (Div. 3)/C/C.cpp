#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s; s = " " + s;
    vector<int> p(m + 1);
    
    set<int> st; priority_queue<char, vector<char>, greater<char> > pq;

    for (int i = 1; i <= m; i++) cin >> p[i], st.insert(p[i]);
    string t; cin >> t;
    for (auto c : t)
        pq.push(c);
    
    for (auto x : st) {
        if (pq.empty()) break;
        s[x] = pq.top(); pq.pop();
    }
    cout << s.substr(1) << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    ll TT; cin >> TT;
    deque<ll> deq;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        deq.push_back(x);
    }
    string s; cin >> s;
    vector<ll> f;
    for (auto op : s) {
        if (op == 'L')
            f.push_back(deq.front()), deq.pop_front();
        else
            f.push_back(deq.back()), deq.pop_back();
    }
    ll now = 1;
    vector<ll> ans;
    reverse(f.begin(), f.end());
    for (auto x : f) {
        now = now * x % TT;
        ans.push_back(now);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

int main() {
    // freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p;
priority_queue<int> pq;

void solve() {
    int n, k; cin >> n >> k;
    p.assign(101, 0);
    for (int i = 0; i < n; i++) { int x; cin >> x; p[x]++;}
    pq.push(0);
    for (int i = 1; i <= 100; i++)
        if (p[i] > 0) pq.push(p[i]);

    while (pq.top() >= k) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        pq.push(y + k - 1);
    }
    ll ans = 0;
    while (!pq.empty())
        ans += pq.top() , pq.pop();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
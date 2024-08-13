#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(3);
    int sum = 0;
    for (int i = 0; i < 3; i++) cin >> a[i], sum += a[i];
    if (sum & 1) {cout << -1 << endl; return;}
    int ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < 3; i++) 
        if (a[i])
            pq.push(a[i]);
    while (pq.size() >= 2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        a -= 1; b -= 1;
        if (a) pq.push(a);
        if (b) pq.push(b);
        ans++;
    }
    cout << ans << endl;
    return ;
}

int main() {
    freopen ("A.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
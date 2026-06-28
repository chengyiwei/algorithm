#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, id;
};

bool cmpl(const Node &a, const Node &b) {
    return a.l < b.l || (a.l == b.l && a.r > b.r);
}

bool cmpr(const Node &a, const Node &b) {
    return a.r > b.r;
}


void solve() {
    int n, f; cin >> n >> f;
    vector<Node> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }

    sort(a.begin() + 1, a.end(), cmpl);
    vector<int> ans;
    vector<int> vis(n + 1, 0);

    long long sum = 0;
    int now = f;
    for (int i = 1; i <= n; i++) {
        if (a[i].l <= now && a[i].r <= now) continue;
        if (a[i].l > now) sum += a[i].l - now;
        sum += a[i].r - a[i].l;
        ans.push_back(a[i].id);
        vis[a[i].id] = 1;
        now = a[i].r;
    }

    sort(a.begin() + 1, a.end(), cmpr);
    for (int i = 1; i <= n; i++) {
        if (vis[a[i].id]) continue;
        sum += a[i].r - a[i].l;
        ans.push_back(a[i].id);
        vis[a[i].id] = 1;
    }

    cout << sum << "\n";
    for (auto id : ans)
        cout << id << " ";    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
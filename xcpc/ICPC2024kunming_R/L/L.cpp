#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    sort(a.begin() + 1, a.end()); 
    sort(b.begin() + 1, b.end());

    int ups = 0, cnt = 0;
    if (a[1] == 1) cnt += 1, a[1] -= 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) cnt += 1, a[i] -= 1;
    }

    for (int i = 1, j = 1; j <= m; j++) {
        while (i <= n && a[i] <= ups) i++, ups++; // 把 a 炸完
        int need = max(b[j] - ups, 0);
        if (need > cnt) {cout << "No\n"; return;}
        cnt -= need;
        ups ++;
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
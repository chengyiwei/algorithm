#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef bitset<maxn> Bit;

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    Bit bs[31];
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 31; j++) bs[j][i] = x >> j & 1;
    }
    Bit vis;
    for (int i = 1; i <= n; i++) vis[i] = 1;
    for (int i = 30; i >= 0; i--) {
        auto now = bs[i] & vis;
        if (now.count() < 2) continue;
        vis = now;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (vis[i]) {
        cout << i << ' '; 
        if (++cnt == 2) break;
    }
    return 0;
}
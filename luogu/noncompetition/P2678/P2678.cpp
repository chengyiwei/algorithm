#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,m,d;
int a[maxn];

bool check (int x) {
    int tot = 0;
    int pos = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] - pos < x) tot++;
        else pos = a[i];
    }
    if (a[n + 1] - pos < x) tot ++;
    return tot <= m;
}

int main() {
    freopen("P2678.in", "r", stdin);
    freopen("P2678.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> d >> n >> m;
    int ans = 1e9;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans = min(ans, a[i] - a[i - 1]);
    }
    a[n + 1] = d; ans = min(ans, d - a[n]);
    int l = 1, r = d;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
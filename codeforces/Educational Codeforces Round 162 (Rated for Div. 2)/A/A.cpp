#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int fst, lst;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {fst = i; break;}
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 1) {lst = i; break;}
    }
    for (int i = fst; i <= lst; i++) {
        if (a[i] == 0) ans ++;
    }
    printf("%d\n", ans);
}
int main() {
    // freopen("A.in", "r", stdin);
    int t; scanf("%d", &t);
    while (t--) solve();
} 
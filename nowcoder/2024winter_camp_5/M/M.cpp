#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf ("%d", &n);
    vector<int> a(n+1),b(n+1);
    int ans = 2;
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d", &x);
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d", &x);
        b[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i] && (a[i] != 1 && a[i] != n))
            ans = 1; 
        if (abs (a[i] - b[i]) == 1)
            ans = 1;
    }
    if (ans == n) printf("-1\n");
    else printf("%d\n", ans);
}

int main () {
    int t; scanf ("%d", &t);
    while (t--) solve();    
}
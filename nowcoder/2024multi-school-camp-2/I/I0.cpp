#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("I.in", "r", stdin);
    freopen ("I0.out", "w", stdout);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(2 * n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (L[a[i]]) R[a[i]] = i;
        else L[a[i]] = i;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int ans = 0;
    do {
        auto b = a;
        int now = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (b[L[p[i]]] == 0 || b[R[p[i]]] == 0) continue;
            for (int j = L[p[i]]; j <= R[p[i]]; j++) {
                if (b[j])
                    cnt += 1;
                b[j] = 0;
            }
            now += cnt * p[i];
        }
        ans = max(ans, now);
    }while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}